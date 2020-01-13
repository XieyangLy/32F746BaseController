
#include <touchgfx/hal/OSWrappers.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include <touchgfx/hal/HAL.hpp>

#include <assert.h>
#include <cmsis_os2.h>

using namespace touchgfx;

static osSemaphoreId_t frame_buffer_sem = 0;
static osMessageQueueId_t vsync_queue = 0;


// Just a dummy value to insert in the VSYNC queue.
static uint32_t dummy = 0x5a;

void OSWrappers::initialize()
{
    // Create a queue of length 1
//    osSemaphoreDef(frame_buffer_sem);
//    frame_buffer_sem = osSemaphoreCreate(osSemaphore(frame_buffer_sem), 1); // Binary semaphore
//    osSemaphoreWait(frame_buffer_sem, osWaitForever); // take the lock
		
		frame_buffer_sem = osSemaphoreNew(1,1,NULL);
	
    // Create a queue of length 1
//    osMessageQDef(vsync_queue, 1, uint32_t);
//    vsync_queue = osMessageCreate(osMessageQ(vsync_queue),NULL);
		vsync_queue = osMessageQueueNew(1,sizeof(uint32_t),NULL);
}

void OSWrappers::takeFrameBufferSemaphore()
{
    assert(frame_buffer_sem);
//    osSemaphoreWait(frame_buffer_sem, osWaitForever);
		osSemaphoreAcquire(frame_buffer_sem, osWaitForever);
}

void OSWrappers::giveFrameBufferSemaphore()
{
    assert(frame_buffer_sem);
//    osSemaphoreRelease(frame_buffer_sem);
		 osSemaphoreRelease(frame_buffer_sem);
}

void OSWrappers::tryTakeFrameBufferSemaphore()
{
    assert(frame_buffer_sem);
//    osSemaphoreWait(frame_buffer_sem, 0);
		osSemaphoreAcquire(frame_buffer_sem, 0);
}

void OSWrappers::giveFrameBufferSemaphoreFromISR()
{
    assert(frame_buffer_sem);
//    osSemaphoreRelease(frame_buffer_sem);
		osSemaphoreRelease(frame_buffer_sem);
}

void OSWrappers::signalVSync()
{
    if (vsync_queue)
    {
//        osMessagePut(vsync_queue, dummy, 0);
				osMessageQueuePut(vsync_queue,&dummy,0,NULL);
    }
}

void OSWrappers::waitForVSync()
{
    if (vsync_queue)
    {
        // First make sure the queue is empty, by trying to remove an element with 0 timeout.
//        osMessageGet(vsync_queue, 0);
				osMessageQueueGet(vsync_queue,&dummy,0,NULL);

        // Then, wait for next VSYNC to occur.
//        osMessageGet(vsync_queue, osWaitForever);
				osMessageQueueGet(vsync_queue,&dummy,0,osWaitForever);
    }
}

void OSWrappers::taskDelay(uint16_t ms)
{
    osDelay(static_cast<uint32_t>(ms));
}


// NOTE:
// The remainder of this file is FreeRTOS-specific. If using a different OS,
// you can just remove all the following code, as it is optional.
// However, if MCU load percentage readout is required, you need to find a way
// to inform TouchGFX of when the idle task is switched in/out and call the
// setMCUActive function accordingly (see below).

//FreeRTOS hook function being called when idle task is switched in or out.
#if 0
static portBASE_TYPE IdleTaskHook(void* p)
{
    if ((int)p) //idle task sched out
    {
        touchgfx::HAL::getInstance()->setMCUActive(true);
    }
    else //idle task sched in
    {
        touchgfx::HAL::getInstance()->setMCUActive(false);
    }
    return pdTRUE;
}
#else

#endif

#include "rtx_os.h"
extern "C"
{
#if 0
    void vApplicationStackOverflowHook(xTaskHandle xTask,
                                       signed portCHAR* pcTaskName)
    {
        while (1);
    }

    void vApplicationMallocFailedHook(xTaskHandle xTask,
                                      signed portCHAR* pcTaskName)
    {
        while (1);
    }

    void vApplicationIdleHook(void)
    {
        // Set task tag in order to have the "IdleTaskHook" function called when the idle task is
        // switched in/out. Used solely for measuring MCU load, and can be removed if MCU load
        // readout is not needed.
        vTaskSetApplicationTaskTag(NULL, IdleTaskHook);
    }
#endif		
		uint32_t osRtxErrorNotify (uint32_t code, void *object_id) 
		{
				(void)object_id;
				switch (code) {
					case osRtxErrorStackUnderflow:
						// Stack overflow detected for thread (thread_id=object_id)
						while(1);
//						break;
					case osRtxErrorISRQueueOverflow:
						// ISR Queue overflow detected when inserting object (object_id)
						while(1);
//						break;
					case osRtxErrorTimerQueueOverflow:
						// User Timer Callback Queue overflow detected for timer (timer_id=object_id)
						while(1);
//						break;
					case osRtxErrorClibSpace:
						// Standard C/C++ library libspace not available: increase OS_THREAD_LIBSPACE_NUM
						break;
					case osRtxErrorClibMutex:
						// Standard C/C++ library mutex initialization failed
						break;
					default:
						break;
				}
				for (;;) {}
			//return 0U;
		}
}
