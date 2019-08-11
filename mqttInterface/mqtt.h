#ifndef _MQTT_IF_H__
#define _MQTT_IF_H__
#include "MQTTClient.h"


struct subTopicType
{
	char *topic;
	void (*handler)(MessageData* data);
};









/*
*信息接收中断
*
*/
void messageArrived(MessageData* data);




#endif
