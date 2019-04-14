
#include "sdcardTest.h"
#include "cmsis_os2.h"
#include "stdio.h"
#include "rl_fs.h"



/*
*文件系统测试APP
*
*/
void fileTestApp(void *param)
{
	FILE *f; 
	
	//初始化文件系统
	if(finit("M0:") != fsOK)
	{
		//err 
		goto errHandler;
	}
	
	//等待sd卡插入
//	while(fs_mc_read_cd(0) != 1)
//	{
//		//等待sd卡插入
//	}
	
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







