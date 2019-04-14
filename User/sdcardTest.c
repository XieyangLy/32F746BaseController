
#include "sdcardTest.h"
#include "cmsis_os2.h"
#include "stdio.h"
#include "rl_fs.h"



/*
*�ļ�ϵͳ����APP
*
*/
char volumeBuf[256];
uint32_t volumeSerial;
uint32_t ullSdCapacity;


void fileTestApp(void *param)
{
	FILE *f; 
	
	//��ʼ���ļ�ϵͳ
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
	
	
	
	
	//�����ļ�������
	if(fmount("M:") != fsOK)
	{
		//err
		goto errHandler;
	}
	
	//���ļ�
	f = fopen("M:\\test.log","w");
	if(f == NULL)
	{
		goto errHandler;
	}else
	{	//�ļ��򿪳ɹ�
		fprintf(f,"hello world\r\n");
		fprintf(f,"bye bye\r\n");
		fflush(f);
		//�ر��ļ�
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







