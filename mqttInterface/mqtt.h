#ifndef _MQTT_IF_H__
#define _MQTT_IF_H__
#include "MQTTClient.h"


struct subTopicType
{
	char *topic;
	void (*handler)(MessageData* data);
};









/*
*��Ϣ�����ж�
*
*/
void messageArrived(MessageData* data);




#endif
