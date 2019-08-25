#include <gui/switchbutton_screen/SwitchButtonView.hpp>
#include <stdio.h>
#ifdef _RTE_
#include "RTE_Components.h"             // Component selection
#endif
#ifdef RTE_CMSIS_RTOS2                  // when RTE component CMSIS RTOS2 is used
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#include "rtx_os.h"
#endif
SwitchButtonView::SwitchButtonView()
{

}

void SwitchButtonView::setupScreen()
{
    SwitchButtonViewBase::setupScreen();
	/*
	*Unicode::snprintf(TextDisPlay_1Buffer,30,"%c","hello");
	*/

	
	Unicode::fromUTF8((uint8_t*)"hello world_123",TextDisPlay_1Buffer,30);
	Unicode::fromUTF8((uint8_t*)"byebye", TextDisPlay_1Buffer, 30);
	//Unicode::UnicodeChar bufferutf8[30] = { 0x74, 0x65, 0x78, 0x74, 0x20, 0x31, 0x3a, 0x0 };

	//Unicode::strncpy(TextDisPlay_1Buffer, "text 1", 30);

	//Unicode::snprintf(TextDisPlay_1Buffer, 30, "%s", "Hello world");
	TextDisPlay_1.resizeToCurrentText();
	TextDisPlay_1.invalidate();
	
}

void SwitchButtonView::tearDownScreen()
{
    SwitchButtonViewBase::tearDownScreen();
}

void SwitchButtonView::updateCurRadioSwitch(int32_t index) 
{
	
}


void SwitchButtonView::updatetext1String(std::string str) 
{
	
//	Unicode::snprintf(TextDisPlay_1Buffer,30,"%c",str.c_str());
	Unicode::fromUTF8((uint8_t*)str.c_str(),TextDisPlay_1Buffer,30);
	TextDisPlay_1.invalidate();
	TextDisPlay_1.resizeToCurrentText();
	TextDisPlay_1.invalidate();

//	printf("text1 update\r\n");

}


void SwitchButtonView::updatetext2String(std::string str) 
{
	/*
	*Unicode::snprintf(TextDisPlay_2Buffer,30,"%s",str.c_str());
	*/
	Unicode::fromUTF8((uint8_t*)str.c_str(),TextDisPlay_2Buffer,30);
	TextDisPlay_2.invalidate();
	TextDisPlay_2.resizeToCurrentText();
	TextDisPlay_2.invalidate();

//	printf("text2 update\r\n");

}


void SwitchButtonView::updatelightStatus(int32_t index,bool status) 
{


}
