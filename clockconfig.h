#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include "stm32f4xx.h"

void PLL_Config(void);

#define RCC_PLLM_25        0x19
#define RCC_PLLN_168      (0xA8)
#define RCC_PLLN_MASK_N6  (0x1BF)
#define RCC_PLLP_2        (00)
#define RCC_PLLQ_4         (0x04)

#endif
