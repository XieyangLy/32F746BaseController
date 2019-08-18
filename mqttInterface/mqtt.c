#include <string.h>
#include "MQTTClient.h"
#include "rl_net.h"
#include "sdcardTest.h"
#include "eventrecorder.h"
#include "mqtt.h"
#include "cJSON.h"
#include "virtualDevice.h"

#ifdef _RTE_
#include "RTE_Components.h"             // Component selection
#endif
#ifdef RTE_CMSIS_RTOS2                  // when RTE component CMSIS RTOS2 is used
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#endif

#if (MQTT_MBEDTLS != 0)
#include "./certificates.h"
#endif

//#define SERVER_NAME "mqtt://192.168.199.230"
#define SERVER_NAME "192.168.199.130"
#if (MQTT_MBEDTLS != 0)
#define SERVER_PORT 8083
#else
#define SERVER_PORT 1883
#endif

#define MAX_Topic_Num	3

/*
*订阅的topic和回调函数
*/
struct subTopicType subscribeTopic[MAX_Topic_Num]= 
{
	[0].topic = "MDK/sample/#",
	[0].handler = messageArrived,
};


unsigned char sendbuf[80], readbuf[80];
MQTTClient client;
Network network;


uint64_t app_mqtt_stk[8192/8];
const osThreadAttr_t app_mqtt_attr = {
	.stack_size = sizeof(app_mqtt_stk),
	.stack_mem = &app_mqtt_stk
};

__NO_RETURN void app_mqtt (void *arg)
{
	(void)arg;
	
#if (MQTT_MBEDTLS != 0)
  TLScert tlscert = {(char *)CA_Cert, NULL, NULL};
#endif
	int rc = 0;
  MQTTPacket_connectData connectData = MQTTPacket_connectData_initializer;
	NetworkInit(&network);
	MQTTMessage message;
	char payload[30];
	osDelay(1000U);
	MQTTClientInit(&client, &network, 30000, sendbuf, sizeof(sendbuf), readbuf, sizeof(readbuf));
	
	#if (MQTT_MBEDTLS != 0)
  if ((rc = NetworkConnectTLS(&network, SERVER_NAME, SERVER_PORT, &tlscert)) != 0)
#else
  if ((rc = NetworkConnect(&network, SERVER_NAME, SERVER_PORT)) != 0)
#endif
    printf("Return code from network connect is %d\n", rc);

#if defined(MQTT_TASK)
  if ((rc = MQTTStartTask(&client)) == 0)
    printf("Return code from start tasks is %d\n", rc);
#endif

  connectData.MQTTVersion = 3;
  connectData.clientID.cstring = "MDK_sample";

  if ((rc = MQTTConnect(&client, &connectData)) != 0)
    printf("Return code from MQTT connect is %d\n", rc);
  else
    printf("MQTT Connected\n");

  if ((rc = MQTTSubscribe(&client, subscribeTopic[0].topic, QOS2, subscribeTopic[0].handler)) != 0)
    printf("Return code from MQTT subscribe is %d\n", rc);
	
	message.qos = QOS1;
	message.retained = 0;
	message.payload = payload;
	sprintf(payload, "hello world\r\n");
	message.payloadlen = strlen(payload);
	if ((rc = MQTTPublish(&client, "MDK/sample/a", &message)) != 0)
		printf("Return code from MQTT publish is %d\n", rc);
	
	for(;;) {
		osDelay(50U);
//		netIF_GetOption(NET_IF_CLASS_ETH | 0, netIF_OptionIP4_Address, (uint8_t *)&addr, sizeof (addr));
	}
}


/*
*信息接收中断
*对应topic:MDK/sample/#
*/
void messageArrived(MessageData* data)
{
	cJSON* root =NULL;
	cJSON* item =NULL;
	cJSON* dev =NULL;
	
  printf("Message arrived on topic %.*s: %.*s\n", data->topicName->lenstring.len, data->topicName->lenstring.data,
  data->message->payloadlen, (char *)data->message->payload);
	
	//对消息进行散转处理
	if(data->message->payloadlen)
	{
		root = cJSON_Parse((char *)data->message->payload);
		if(root == NULL)
		{		
			//cJSON_Delete(root);
			return;
		}
		
	}
	
	//地址
    item = cJSON_GetArrayItem(root,0);
    printf("mqtt data, addr=%s\r\n",item->valuestring);
    //类型
    item = cJSON_GetArrayItem(root,1);
    printf("mqtt data, type=%d\r\n",item->valueint);
    //设备
    dev = cJSON_GetArrayItem(root,2);
    //控制字
    item = cJSON_GetArrayItem(dev,0);
    printf("mqtt data, dev/ctrl=%d\r\n",item->valueint);
    //状态
    item = cJSON_GetArrayItem(dev,1);
    printf("mqtt data, dev/status=%d\r\n",item->valueint);
    if(item->valueint == 1)
    {
        virtualDeviceLcd(1,NULL);
    }else if(item->valueint == 0){
        virtualDeviceLcd(0,NULL);
    }
		cJSON_Delete(root);
}


void mqttIfInit (void)
{
#if (MQTT_MBEDTLS != 0)
  TLScert tlscert = {(char *)CA_Cert, NULL, NULL};
#endif

  int rc = 0;
  MQTTPacket_connectData connectData = MQTTPacket_connectData_initializer;

  NetworkInit(&network);

  MQTTClientInit(&client, &network, 30000, sendbuf, sizeof(sendbuf), readbuf, sizeof(readbuf));

#if (MQTT_MBEDTLS != 0)
  if ((rc = NetworkConnectTLS(&network, SERVER_NAME, SERVER_PORT, &tlscert)) != 0)
#else
  if ((rc = NetworkConnect(&network, SERVER_NAME, SERVER_PORT)) != 0)
#endif
    printf("Return code from network connect is %d\n", rc);

#if defined(MQTT_TASK)
  if ((rc = MQTTStartTask(&client)) == 0)
    printf("Return code from start tasks is %d\n", rc);
#endif

  connectData.MQTTVersion = 3;
  connectData.clientID.cstring = "MDK_sample";

  if ((rc = MQTTConnect(&client, &connectData)) != 0)
    printf("Return code from MQTT connect is %d\n", rc);
  else
    printf("MQTT Connected\n");

  if ((rc = MQTTSubscribe(&client, subscribeTopic[0].topic, QOS2, messageArrived)) != 0)
    printf("Return code from MQTT subscribe is %d\n", rc);

	while(1)
	{
		MQTTMessage message;
    char payload[30];

    message.qos = QOS1;
    message.retained = 0;
    message.payload = payload;
    sprintf(payload, "hello world\r\n");
    message.payloadlen = strlen(payload);
    if ((rc = MQTTPublish(&client, "MDK/sample/a", &message)) != 0)
      printf("Return code from MQTT publish is %d\n", rc);
		break;
	}


//  NetworkDisconnect(&network);
//  printf("MQTT Disconnected\n");
}
