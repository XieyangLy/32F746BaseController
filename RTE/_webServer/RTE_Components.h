
/*
 * Auto generated Run-Time-Environment Configuration File
 *      *** Do not modify ! ***
 *
 * Project: '32F746Demo' 
 * Target:  'webServer' 
 */

#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H


/*
 * Define the Device Header File: 
 */
#define CMSIS_device_header "stm32f7xx.h"

/*  ARM::CMSIS:RTOS2:Keil RTX5:Source:5.5.0 */
#define RTE_CMSIS_RTOS2                 /* CMSIS-RTOS2 */
        #define RTE_CMSIS_RTOS2_RTX5            /* CMSIS-RTOS2 Keil RTX5 */
        #define RTE_CMSIS_RTOS2_RTX5_SOURCE     /* CMSIS-RTOS2 Keil RTX5 Source */
/*  ARM::Security:mbed TLS:2.17.0 */
#define RTE_Security_mbedTLS            /* Security mbed TLS */
/*  Keil.ARM Compiler::Compiler:Event Recorder:DAP:1.4.0 */
#define RTE_Compiler_EventRecorder
          #define RTE_Compiler_EventRecorder_DAP
/*  Keil.ARM Compiler::Compiler:I/O:STDERR:Breakpoint:1.2.0 */
#define RTE_Compiler_IO_STDERR          /* Compiler I/O: STDERR */
          #define RTE_Compiler_IO_STDERR_BKPT     /* Compiler I/O: STDERR Breakpoint */
/*  Keil.ARM Compiler::Compiler:I/O:STDOUT:EVR:1.2.0 */
#define RTE_Compiler_IO_STDOUT          /* Compiler I/O: STDOUT */
          #define RTE_Compiler_IO_STDOUT_EVR      /* Compiler I/O: STDOUT EVR */
/*  Keil.MDK-Pro::Network:CORE:IPv4/IPv6 Debug:7.10.0 */
#define RTE_Network_Core                /* Network Core */
          #define RTE_Network_IPv4                /* Network IPv4 Stack */
          #define RTE_Network_IPv6                /* Network IPv6 Stack */
          #define RTE_Network_Debug               /* Network Debug Version */
/*  Keil.MDK-Pro::Network:Interface:ETH:7.10.0 */
#define RTE_Network_Interface_ETH_0     /* Network Interface ETH 0 */

/*  Keil.MDK-Pro::Network:Service:DNS Client:7.10.0 */
#define RTE_Network_DNS_Client          /* Network DNS Client */
/*  Keil.MDK-Pro::Network:Service:Web Server Compact:HTTP:7.10.0 */
#define RTE_Network_Web_Server_RO       /* Network Web Server with Read-only Web Resources */
/*  Keil.MDK-Pro::Network:Socket:BSD:7.10.0 */
#define RTE_Network_Socket_BSD          /* Network Socket BSD */
/*  Keil.MDK-Pro::Network:Socket:TCP:7.10.0 */
#define RTE_Network_Socket_TCP          /* Network Socket TCP */
/*  Keil.MDK-Pro::Network:Socket:UDP:7.10.0 */
#define RTE_Network_Socket_UDP          /* Network Socket UDP */
/*  Keil::CMSIS Driver:Ethernet MAC:1.6.0 */
#define RTE_Drivers_ETH_MAC0            /* Driver ETH_MAC0 */
/*  Keil::CMSIS Driver:Ethernet PHY:LAN8742A:1.2.0 */
#define RTE_Drivers_PHY_LAN8742A        /* Driver PHY LAN8742A */
/*  Keil::CMSIS Driver:MCI:1.6.0 */
#define RTE_Drivers_MCI0                /* Driver MCI0 */
        #define RTE_Drivers_MCI1                /* Driver MCI1 */
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
/*  Keil::Device:STM32Cube HAL:I2C:1.2.6 */
#define RTE_DEVICE_HAL_I2C
/*  Keil::Device:STM32Cube HAL:LTDC:1.2.6 */
#define RTE_DEVICE_HAL_LTDC
/*  Keil::Device:STM32Cube HAL:PWR:1.2.6 */
#define RTE_DEVICE_HAL_PWR
/*  Keil::Device:STM32Cube HAL:RCC:1.2.6 */
#define RTE_DEVICE_HAL_RCC
/*  Keil::Device:STM32Cube HAL:SD:1.2.6 */
#define RTE_DEVICE_HAL_SD
/*  Keil::Device:STM32Cube HAL:SDRAM:1.2.6 */
#define RTE_DEVICE_HAL_SDRAM
/*  Keil::Device:STM32Cube HAL:UART:1.2.6 */
#define RTE_DEVICE_HAL_UART
/*  Keil::Device:STM32Cube HAL:USART:1.2.6 */
#define RTE_DEVICE_HAL_USART
/*  Keil::Device:Startup:1.2.2 */
#define RTE_DEVICE_STARTUP_STM32F7XX    /* Device Startup for STM32F7 */
/*  MDK-Packs::Data Exchange:JSON:cJSON:1.7.7 */
#define RTE_DataExchange_JSON_cJSON     /* cJSON */
/*  MDK-Packs::IoT Client:MQTTClient-C:1.1.0 */
#define RTE_IoT_Client_MQTTClient_C     /* MQTTClient-C IoT Client */
/*  MDK-Packs::IoT Utility:MQTTPacket:1.1.0 */
#define RTE_IoT_MQTTPacket              /* IoT MQTTPacket */
/*  MDK-Packs::IoT Utility:Socket:MDK Network:1.1.0 */
#define RTE_IoT_Socket                  /* IoT Socket */
        #define RTE_IoT_Socket_MDK_Network      /* IoT Socket: MDK::Network */


#endif /* RTE_COMPONENTS_H */
