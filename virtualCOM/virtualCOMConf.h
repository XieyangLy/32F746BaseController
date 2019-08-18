
#ifndef _VIRTUAL_COM_H__
#define _VIRTUAL_COM_H__


/*
*消息掩码
*/

#define CDC_ACM_INITIALIZE_MASK 	0x00000001ul						//flags mask 掩码
#define CDC_ACM_MASG_MASK					0x00000006ul




/*
*消息标志
*/

#define CDC_ACM_INITIALIZE_FLAG 	0x00000001ul						//初始化消息标志
#define CDC_ACM_MASG_Recv_FLAG		0x00000002ul						//收到消息标志
#define CDC_ACM_MASG_Send_FLAG		0x00000004ul						//发送消息标志












#endif

