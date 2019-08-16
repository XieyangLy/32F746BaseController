## 32F746RL-TCPNetDemo


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



## TODO
添加文件系统,使用U盘
添加音频






















