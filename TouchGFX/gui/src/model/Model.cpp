#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdio.h>


#ifdef _RTE_
#include "RTE_Components.h"             // Component selection
#endif

#ifdef RTE_CMSIS_RTOS2                  // when RTE component CMSIS RTOS2 is used
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#include "rtx_os.h"
#endif


typedef struct {
	uint8_t buf[50];
	uint8_t cmd;
	uint8_t idx;
}TouchGFX_OBJ_t;

#ifdef _HARD_DEVICE_
extern osMessageQueueId_t tid_TouchGFX_MsgQueue;
#endif





Model::Model() : modelListener(0),
								text1("text1"),
								text2("text2"),
								radioSwitch(0)
{
	
}

void Model::tick()
{
#ifdef _HARD_DEVICE_
	TouchGFX_OBJ_t msg;
	osStatus_t status;
	
	
	//等待信号
	status = osMessageQueueGet(tid_TouchGFX_MsgQueue,&msg,NULL,0U);
	if(osOK == status)
	{
		printf("message get\r\n");
		//处理消息
		switch(msg.cmd)
		{
			case 1:		//lightStatus 
				lightStatus[msg.idx] = msg.buf[0];
				if(modelListener != 0)
				{
					modelListener->notifylightStatusChanged(msg.idx,lightStatus[msg.idx]);
				}
				break;
			case 2:		//text
				if(msg.idx == 1)
				{
					printf("text1 message get\r\n");
					text1 = (char*)msg.buf;
					if(modelListener != 0)
					{
						modelListener->notifytext1StringChanged(text1);
					}
				}else if(msg.idx == 2)
				{
					printf("text2 message get\r\n");
					text2 = (char*)msg.buf;
					if(modelListener != 0)
					{
						modelListener->notifytext2StringChanged(text2);
					}
				}
				break;
			case 3:		//radioSwitch
				radioSwitch = msg.idx;
				if(modelListener != 0)
				{
					modelListener->notifyCurRadioSwitchChanged(radioSwitch);
				}
				break;
		
		}
		
	}
#endif
}
