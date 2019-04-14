
/*
 * Auto generated Run-Time-Environment Configuration File
 *      *** Do not modify ! ***
 *
 * Project: '32F746Demo' 
 * Target:  'Target 1' 
 */

#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H


/*
 * Define the Device Header File: 
 */
#define CMSIS_device_header "stm32f7xx.h"

/*  ARM::CMSIS:RTOS2:Keil RTX5:Library:5.5.0 */
#define RTE_CMSIS_RTOS2                 /* CMSIS-RTOS2 */
        #define RTE_CMSIS_RTOS2_RTX5            /* CMSIS-RTOS2 Keil RTX5 */
/*  Keil.ARM Compiler::Compiler:Event Recorder:DAP:1.4.0 */
#define RTE_Compiler_EventRecorder
          #define RTE_Compiler_EventRecorder_DAP
/*  Keil.ARM Compiler::Compiler:I/O:File:File System:1.2.0 */
#define RTE_Compiler_IO_File            /* Compiler I/O: File */
          #define RTE_Compiler_IO_File_FS         /* Compiler I/O: File (File System) */
/*  Keil.ARM Compiler::Compiler:I/O:STDOUT:EVR:1.2.0 */
#define RTE_Compiler_IO_STDOUT          /* Compiler I/O: STDOUT */
          #define RTE_Compiler_IO_STDOUT_EVR      /* Compiler I/O: STDOUT EVR */
/*  Keil.MDK-Plus::File System:CORE:LFN Debug:6.11.0 */
#define RTE_FileSystem_Core             /* File System Core */
          #define RTE_FileSystem_LFN              /* File System with Long Filename support */
          #define RTE_FileSystem_Debug            /* File System Debug Version */
/*  Keil.MDK-Plus::File System:Drive:RAM:6.11.0 */
#define RTE_FileSystem_Drive_RAM        /* File System RAM Drive */
/*  Keil.MDK-Plus::Network:CORE:IPv4 Debug:7.10.0 */
#define RTE_Network_Core                /* Network Core */
          #define RTE_Network_IPv4                /* Network IPv4 Stack */
          #define RTE_Network_Debug               /* Network Debug Version */
/*  Keil.MDK-Plus::Network:Interface:ETH:7.10.0 */
#define RTE_Network_Interface_ETH_0     /* Network Interface ETH 0 */

/*  Keil.MDK-Plus::Network:Service:Web Server:HTTP:7.10.0 */
#define RTE_Network_Web_Server_FS       /* Network Web Server with Web Resources on File System */
/*  Keil.MDK-Plus::Network:Socket:TCP:7.10.0 */
#define RTE_Network_Socket_TCP          /* Network Socket TCP */
/*  Keil.MDK-Plus::Network:Socket:UDP:7.10.0 */
#define RTE_Network_Socket_UDP          /* Network Socket UDP */
/*  Keil::CMSIS Driver:Ethernet MAC:1.6.0 */
#define RTE_Drivers_ETH_MAC0            /* Driver ETH_MAC0 */
/*  Keil::CMSIS Driver:Ethernet PHY:LAN8742A:1.2.0 */
#define RTE_Drivers_PHY_LAN8742A        /* Driver PHY LAN8742A */
/*  Keil::Device:STM32Cube Framework:Classic:1.2.6 */
#define RTE_DEVICE_FRAMEWORK_CLASSIC
/*  Keil::Device:STM32Cube HAL:Common:1.2.6 */
#define RTE_DEVICE_HAL_COMMON
/*  Keil::Device:STM32Cube HAL:Cortex:1.2.6 */
#define RTE_DEVICE_HAL_CORTEX
/*  Keil::Device:STM32Cube HAL:DMA:1.2.6 */
#define RTE_DEVICE_HAL_DMA
/*  Keil::Device:STM32Cube HAL:GPIO:1.2.6 */
#define RTE_DEVICE_HAL_GPIO
/*  Keil::Device:STM32Cube HAL:PWR:1.2.6 */
#define RTE_DEVICE_HAL_PWR
/*  Keil::Device:STM32Cube HAL:RCC:1.2.6 */
#define RTE_DEVICE_HAL_RCC
/*  Keil::Device:STM32Cube HAL:UART:1.2.6 */
#define RTE_DEVICE_HAL_UART
/*  Keil::Device:STM32Cube HAL:USART:1.2.6 */
#define RTE_DEVICE_HAL_USART
/*  Keil::Device:Startup:1.2.2 */
#define RTE_DEVICE_STARTUP_STM32F7XX    /* Device Startup for STM32F7 */


#endif /* RTE_COMPONENTS_H */
