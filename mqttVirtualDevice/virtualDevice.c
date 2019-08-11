#include "stdint.h"
#include <string.h>
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2


extern char lcd_text[2][20+1];
extern osThreadId_t TID_Display;









void virtualDeviceLcd(uint32_t cmd,char* str)
{
	switch(cmd)
	{
		case 0:
				strcpy (lcd_text[0], "hello world");
        osThreadFlagsSet (TID_Display, 0x01);
			break;
		case 1:
			  strcpy (lcd_text[0], "byebye");
        osThreadFlagsSet (TID_Display, 0x01);
			break;
	
	}

}

















