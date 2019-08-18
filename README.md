# 32F746基础控制器项目

## 已开发内容

1、移除webFile中关于LCD的内容
2、移除HTTP_Server.c/HTTP_Server_CGI.c中LCD相关内容
3、添加touchGFX{
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
4、加入USB虚拟串口，可以通过虚拟串口与系统通信


## TODO
### 系统功能模块
* 添加文件系统,使用U盘
* 添加音频
* 调试组件: 基于segger rtt和event recoder
* 增加流程控制组件: 命令堆，任务链，
* 数据结构组件: 复合链表，复合堆
* 完善系统架构
* 封装touchGFX基础包





















