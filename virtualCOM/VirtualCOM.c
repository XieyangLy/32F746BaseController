/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::USB:Device
 * Copyright (c) 2004-2018 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    VirtualCOM.c
 * Purpose: USB Device Virtual COM Port demonstration
 *----------------------------------------------------------------------------*/

#include "main.h"
#include "rl_usb.h"                     /* RL-USB function prototypes         */
#include "RTE_Components.h"
#include "virtualCOMConf.h"


#ifdef RTE_Compiler_EventRecorder
#include "EventRecorder.h"
#endif

// Main stack size must be multiple of 8 Bytes
#define APP_MAIN_STK_SZ (1024U)
uint64_t usbVirtualCOM_stk[APP_MAIN_STK_SZ / 8];
const osThreadAttr_t usbVirtualCOM_attr = {
  .stack_mem  = &usbVirtualCOM_stk[0],
  .stack_size = sizeof(usbVirtualCOM_stk)
};

osEventFlagsId_t virtualCom_evt_id;                  // message queue id
osMutexId_t virtualCom_mutex_id;

const osMutexAttr_t virtualCom_Mutex_attr = {
  "myThreadMutex",     // human readable mutex name
  osMutexRecursive,    // attr_bits
  NULL,                // memory for control block   
  0U                   // size for control block
};



int32_t virtualComMsgLocalHandler(uint8_t *pData,uint32_t length);
int32_t (*virtualComMsgHandler)(uint8_t *pData,uint32_t length) = virtualComMsgLocalHandler;

/*------------------------------------------------------------------------------
 *        Application
 *----------------------------------------------------------------------------*/
__NO_RETURN void usbVirtualCOM_main (void *arg) {
  (void)arg;
	uint32_t flags;
	
#ifdef RTE_Compiler_EventRecorder
  EventRecorderInitialize(0, 1);
  EventRecorderEnable (EventRecordError, 0xA0U, 0xA6U);  /* USBD Error Events */
  EventRecorderEnable (EventRecordAll  , 0xA0U, 0xA0U);  /* Core Events */
  EventRecorderEnable (EventRecordAll  , 0xA4U, 0xA4U);  /* CDC Events */
#endif
  USBD_Initialize         (0);          /* USB Device 0 Initialization        */
  USBD_Connect            (0);          /* USB Device 0 Connect               */
	
	//创建event
	virtualCom_evt_id = osEventFlagsNew(NULL);
	virtualCom_mutex_id = osMutexNew(&virtualCom_Mutex_attr);
	
	
	//等待
	flags = osEventFlagsWait (virtualCom_evt_id,CDC_ACM_INITIALIZE_MASK,osFlagsWaitAny, osWaitForever);
  for (;;) {                            // Loop forever
		//等待消息
		flags = osEventFlagsWait (virtualCom_evt_id,CDC_ACM_MASG_MASK,osFlagsWaitAny, osWaitForever);
//		if(flags & CDC_ACM_MASG_FLAG)
//		{	//收到虚拟串口消息
//		
//		}
		if(flags & CDC_ACM_MASG_Send_FLAG)
		{
			
		}
		
    osDelay(10U);
  }
}


/*
*数据发送
*参数:pData:数据指针，length数据长度
*/
int32_t usbVirtualComSend(const uint8_t *pData,uint32_t length)
{
	uint32_t cnt = 0;
	osStatus_t result;
	
	while(length)
	{
		//获取锁,等待时间根据实际项目需求配置
		result = osMutexAcquire(virtualCom_mutex_id,osWaitForever);
		if(result == osOK)
		{
			//数据发送
			cnt = USBD_CDC_ACM_WriteData(0,pData,length);
			length -= cnt;
		}else{
			return -1;
		}
	}
	return 0;
}



#define usb_CDC_ACM_BufLength	500UL
uint8_t usb_CDC_ACM_DataBuf[usb_CDC_ACM_BufLength];
/*
*数据接收
*参数:待读取数据长度
*返回值:无
*/
void virtualCOMMsgHandle(uint32_t len)
{
	int32_t cnt;
	//获取数据，根据实际情况进行组解包
	cnt = USBD_CDC_ACM_ReadData(0U,usb_CDC_ACM_DataBuf,usb_CDC_ACM_BufLength);
	
	//数据处理回调
	virtualComMsgLocalHandler(usb_CDC_ACM_DataBuf,cnt);

}

/*
*消息回调注册函数
*参数:消息回调函数
*返回值:原本的消息回调函数
*/
int32_t (*(virtualCOMMsgHandleRegister(int32_t (*fn)(uint8_t *pData,uint32_t length))))(uint8_t *pData,uint32_t length)
{
	int32_t (*tmp)(uint8_t *pData,uint32_t length) = virtualComMsgHandler;
	virtualComMsgHandler = fn;
	
	return tmp;
}


/*
*虚拟化处理，直接丢弃数据
*/
int32_t virtualComMsgLocalHandler(uint8_t *pData,uint32_t length)
{
	(void)(pData);
	(void)(length);
	return 0;
}

