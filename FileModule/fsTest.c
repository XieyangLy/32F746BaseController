/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "RTE_Components.h" 
#include "rl_net.h"                     // Keil.MDK-Pro::Network:CORE
#include "stm32f7xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "./fstest.h"
#include "rl_fs.h"


#ifdef RTE_Compiler_EventRecorder
#include "EventRecorder.h"
#endif

#define FSDEMO_ATTR_STK_SZ (4096U)
uint64_t fsDemo_attr_stk[FSDEMO_ATTR_STK_SZ / 8];
const osThreadAttr_t fsDemo_attr = {
  .stack_mem  = &fsDemo_attr_stk[0],
  .stack_size = sizeof(fsDemo_attr_stk),
	.priority = osPriorityAboveNormal,
};



/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void sd_rlfs_demo(void *arg);


/*
*创建fatfs demo 
*
*/
void sd_rlfs_demo_task_create(void)
{
//	fsDemo_attr.stack_mem  = &fsDemo_attr_stk[0];
//	fsDemo_attr.stack_size = sizeof(fsDemo_attr_stk);
//	fsDemo_attr.priority = osPriorityAboveNormal;
	osThreadNew(sd_rlfs_demo, NULL, &fsDemo_attr);

}

char volumeBuf[256];
uint32_t volumeSerial;
uint32_t ullSdCapacity;

__NO_RETURN void sd_rlfs_demo(void *arg) {

	//初始化 
	FILE *f; 
	
	//初始化文件系统
	if(finit("M:") != fsOK)
	{
		//err 
		goto errHandler;
	}
	
//	if(fvol("M0:",(char*)volumeBuf,&volumeSerial) == 0)
//	{
//		
//	}
//	ullSdCapacity = ffree("M0:");
//	
//	
//	
	
	
	
	
	//挂载文件驱动器
	if(fmount("M:") != fsOK)
	{
		//err
		goto errHandler;
	}
	
	//打开文件
	f = fopen("M:\\test.log","w");
	if(f == NULL)
	{
		goto errHandler;
	}else
	{	//文件打开成功
		printf("file open suc\r\n");
		fprintf(f,"hello world\r\n");
		fprintf(f,"bye bye\r\n");
		fflush(f);
		//关闭文件
		fclose(f);
		printf("file close suc\r\n");
	}
	
	funmount("M:");
	funinit("M:");
	
	
	
	while(1)
	{
		//测试读写
	
	
	}	
	
	errHandler:
	while(1)
	{
		printf("file err\r\n");
		osDelay(osWaitForever);
	}	

}




void fileTestApp(void *param)
{

}



