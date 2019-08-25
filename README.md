# 32F746基础控制器项目

## TODO
### 系统功能模块
* 添加文件系统,使用U盘
* 添加音频
* 调试组件: 基于segger rtt和event recoder
* 增加流程控制组件: 命令堆，任务链，
* 数据结构组件: 复合链表，复合堆
* 完善系统架构
* 封装touchGFX基础包
* 时间基准

touchGFX中的printf()输出失效


## changelog

2019-08-25
1、添加screen切换时的更新机制
2、解决wildcard字符串重绘为更短字符串部分内容丢失的问题。




old_update
	1.移除webFile中关于LCD的内容
	2.移除HTTP_Server.c/HTTP_Server_CGI.c中LCD相关内容
	3.添加touchGFX{
		添加相关文件，确保编译通过	--done
		添加相关初始化函数			--done
		添加GRAPHICS_HW_Init();		--done
		添加GRAPHICS_Init();		--done
		添加默认任务(用于启动系统);	--done
		{
			httpServer_main
			app_mqtt
			GRAPHICS_MainTask
		}
	}
	4.加入USB虚拟串口，可以通过虚拟串口与系统通信
	5.mqtt task中发现bug，会导致系统死机，原因:当网络为联通时，如果调用MQTTConnect连接服务器，会导致HardFault ，通过添加线程时间解决，在连接前死等网络就绪
	6.添加dhcp 回调函数，获取ip地址后向mqtt任务发送线程事件
	7.加入netETH_Notify事件回调，打印上线，掉线等信息，以便后续使用
	8.修改系统时钟注释，原本的218MHz修改为200MHz，以及相关分频器数值
	9.添加debug日志模块
	10.添加touchGFX项目生成MDK工程


























