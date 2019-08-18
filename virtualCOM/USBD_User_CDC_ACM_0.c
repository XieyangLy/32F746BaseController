/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::USB:Device
 * Copyright (c) 2004-2018 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    USBD_User_CDC_ACM_0.c
 * Purpose: USB Device Communication Device Class (CDC)
 *          Abstract Control Model (ACM) User module
 * Rev.:    V6.4.0
 *----------------------------------------------------------------------------*/
/**
 * \addtogroup usbd_cdcFunctions
 *
 * USBD_User_CDC_ACM_0.c implements the application specific functionality
 * of the CDC ACM class and is used to receive and send data to the USB Host.
 *
 * The implementation must match the configuration file USBD_Config_CDC_0.h.
 * The following values in USBD_Config_CDC_0.h affect the user code:
 *
 *  - 'Maximum Communication Device Send Buffer Size' specifies the maximum
 *    value for \em len in \ref USBD_CDC_ACM_WriteData
 *
 *  - 'Maximum Communication Device Receive Buffer Size' specifies the maximum
 *    value for \em len in \ref USBD_CDC_ACM_ReadData
 *
 */
 
 
//! [code_USBD_User_CDC_ACM]
 
#include <stdint.h>
#include <stdbool.h>
#include "virtualCOMConf.h"
 
#include "rl_usb.h"
 
// Local Variables
static   CDC_LINE_CODING        cdc_acm_line_coding = { 0U, 0U, 0U, 0U };
extern osEventFlagsId_t virtualCom_evt_id;                  // message queue id
extern osMutexId_t virtualCom_mutex_id;
extern void virtualCOMMsgHandle(uint32_t len);

 
// Called during USBD_Initialize to initialize the USB CDC class instance (ACM).
void USBD_CDC0_ACM_Initialize (void) {
  // Add code for initialization
	//���������ʼ�����紮�ڵ�
	
	//���ݴ����̴߳���
	osEventFlagsSet (virtualCom_evt_id, 0x0001U);            // set the flag 0x0001U for event sig1_id,���ڸ�֪���̳߳�ʼ��USB CDC class instance

}
 
 
// Called during USBD_Uninitialize to de-initialize the USB CDC class instance (ACM).
void USBD_CDC0_ACM_Uninitialize (void) {
  // Add code for de-initialization
	
	//ɱ����ʼ��ʱ�������߳�

	//�����豸��ȥ��ʼ��
	
}
 
 
// Called upon USB Bus Reset Event.
void USBD_CDC0_ACM_Reset (void) {
  // Add code for reset
	
	//��USB���߸�λʱ���лص������������������Ӧ���������ϴ����
	
}
 
 
// Callback function called upon reception of request send encapsulated command sent by the USB Host.
// \param[in]   buf           buffer that contains send encapsulated command request.
// \param[in]   len           length of send encapsulated command request.
// \return      true          send encapsulated command request processed.
// \return      false         send encapsulated command request not supported or not processed.
bool USBD_CDC0_ACM_SendEncapsulatedCommand (const uint8_t *buf, uint16_t len) {
  return true;
}
 
 
// Callback function called upon reception of request to get encapsulated response sent by the USB Host.
// \param[in]   max_len       maximum number of data bytes that USB Host expects to receive
// \param[out]  buf           pointer to buffer containing get encapsulated response to be returned to USB Host.
// \param[out]  len           pointer to number of data bytes to be returned to USB Host.
// \return      true          get encapsulated response request processed.
// \return      false         get encapsulated response request not supported or not processed.
bool USBD_CDC0_ACM_GetEncapsulatedResponse (uint16_t max_len, uint8_t **buf, uint16_t *len) {
  return true;
}
 
 
// Called upon USB Host request to change communication settings.
// \param[in]   line_coding   pointer to CDC_LINE_CODING structure.
// \return      true          set line coding request processed.
// \return      false         set line coding request not supported or not processed.
bool USBD_CDC0_ACM_SetLineCoding (const CDC_LINE_CODING *line_coding) {
  // Add code for set line coding
  // Store requested settings to local variable
  cdc_acm_line_coding = *line_coding;
	
	//�����ת��Ϊuart������Ҫ�޸���Ӧ������
	
	
  return true;
}
 
 
// Called upon USB Host request to retrieve communication settings.
// \param[out]  line_coding   pointer to CDC_LINE_CODING structure.
// \return      true          get line coding request processed.
// \return      false         get line coding request not supported or not processed.
bool USBD_CDC0_ACM_GetLineCoding (CDC_LINE_CODING *line_coding) {
 
  // Load settings from ones stored on USBD_CDC0_ACM_SetLineCoding callback
  *line_coding = cdc_acm_line_coding;
 
  return true;
}
 
 
// Called upon USB Host request to set control line states.
// \param [in]  state         control line settings bitmap.
//                - bit 0: DTR state
//                - bit 1: RTS state
// \return      true          set control line state request processed.
// \return      false         set control line state request not supported or not processed.
bool USBD_CDC0_ACM_SetControlLineState (uint16_t state) {
  // Add code for set control line state
 
  (void)(state);
 
  return true;
}
 
 
// Called when new data was received.
// \param [in]  len           number of bytes available for reading.
void USBD_CDC0_ACM_DataReceived (uint32_t len) {
  // Add code for handling new data reception
	
	//���յ�����ʱϵͳ���иûص�
	(void)(len);
	
//	osEventFlagsSet(virtualCom_evt_id,CDC_ACM_MASG_Recv_FLAG);
	virtualCOMMsgHandle(len);
	
	

	
	//�����ݽ��д���,���緢�ͻ�ȥ
	
}
 
 
// Called when when all data was sent.
void USBD_CDC0_ACM_DataSent (void) {
  // Add code for handling new data send
	osMutexRelease(virtualCom_mutex_id);
}



//! [code_USBD_User_CDC_ACM]
