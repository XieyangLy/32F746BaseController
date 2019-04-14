
#include "sdcardTest.h"
#include "cmsis_os2.h"
#include "stdio.h"
#include "rl_fs.h"



/*
*文件系统测试APP
*
*/
char volumeBuf[256];
uint32_t volumeSerial;
uint32_t ullSdCapacity;


void fileTestApp(void *param)
{
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
		fprintf(f,"hello world\r\n");
		fprintf(f,"bye bye\r\n");
		fflush(f);
		//关闭文件
		fclose(f);
	}
	
	funmount("M:");
	funinit("M:");
	
	
	errHandler:
	while(1)
	{
		osDelay(osWaitForever);
	}
}







