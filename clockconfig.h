#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include "stm32f4xx.h"

void PLL_Config(void);

#define RCC_PLLM_25       0x19
#define RCC_PLLN_168      (10101000<<6)
#define RCC_PLLP_2        (00<<16)

#endif
