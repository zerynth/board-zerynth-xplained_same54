#ifndef __VBOARD__
#define __VBOARD__


#define VBOARD_SLEEP_MICRO_COMPENSATION	50

extern uint8_t __ramvectors__[];

#define CORTEX_FLASH_VTABLE 0x00000000
#define CORTEX_VTOR_INIT ((uint32_t)(&__ramvectors__))
#define CORTEX_VECTOR_COUNT	138

//CORTEX_VECTOR_COUNT = total number - 16

//check if the file is compiled sartup_same54.class 



#define CORTEX_ENABLE_WFI_IDLE          TRUE
#define CORTEX_SIMPLIFIED_PRIORITY		FALSE
#ifndef CORTEX_USE_FPU
#define CORTEX_USE_FPU					TRUE
#endif

#define PORT_PRIO_BITS 3
#define PORT_PRIO_MASK(n) ((n) << (8 - PORT_PRIO_BITS))

#define ZERYNTH_USLEEP_USE_SYSTICK 1
#define RTOS_IRQ_PROLOGUE 1
#define VHAL_SYSTEM_INIT 1

#define VHAL_SER_RXFIFO_LEN 256
#define VHAL_SER_TXFIFO_LEN 256
#define __FPU_PRESENT 1U
#endif
