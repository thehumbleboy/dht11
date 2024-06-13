#include "clockconfig.h"

void PLL_Config(void){
	//Set HSE as clock source, because the PLL uses HSE as clock source
	FLASH->ACR |= FLASH_ACR_LATENCY_2WS;
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;// AHB prescaler divided by 2
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;//APB1 Prescaler
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;//APB2 Prescaler

	//RCC->CFGR |= RCC_CFGR_SW_HSE;//Selecting HSE as system clock

	RCC->CR |= RCC_CR_HSEON;//Setting the HSE to be on

	while(!(RCC->CR & RCC_CR_HSERDY));//Checking if the HSERDY bit is on

	//Set Power Enable clock
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;

	//Set voltage regulator
	PWR->CR |= PWR_CR_VOS;

	//Configure PLLM, PLLN, PLLP in main PLL
	RCC->PLLCFGR |= RCC_PLLM_25;
	RCC->PLLCFGR |= RCC_PLLN_168;
	RCC->PLLCFGR |= RCC_PLLP_2;

	//Setting PLL as system clock
		RCC->CR |= RCC_CR_PLLON;

		while(!(RCC->CR & RCC_CR_PLLRDY));//Checking if the PLL is ready to be used

	RCC->CFGR |= RCC_CFGR_SW_PLL;

	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));


}
