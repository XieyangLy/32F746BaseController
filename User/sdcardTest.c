
#include "sdcardTest.h"
#include "cmsis_os2.h"
#include "stdio.h"
#include "rl_fs.h"



/*
*�ļ�ϵͳ����APP
*
*/
void fileTestApp(void *param)
{
	FILE *f; 
	
	//��ʼ���ļ�ϵͳ
	if(finit("M0:") != fsOK)
	{
		//err 
		goto errHandler;
	}
	
	//�ȴ�sd������
//	while(fs_mc_read_cd(0) != 1)
//	{
//		//�ȴ�sd������
//	}
	
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







