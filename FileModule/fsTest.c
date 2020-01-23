/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "RTE_Components.h" 
#include "rl_net.h"                     // Keil.MDK-Pro::Network:CORE
#include "stm32f7xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "./fstest.h"


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



__NO_RETURN void sd_rlfs_demo(void *arg) {

	//初始化 
	
	
	
	while(1)
	{
		//测试读写
	
	
	}
}


