#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "clockconfig.h"

GPIO_InitTypeDef gpio_int;
void GPIO_Initialize(void);
void GPIO_Output_config(GPIO_InitTypeDef *GPIO_InitStruct);

int main(void)
{
	PLL_Config();
	SystemCoreClockUpdate();
	GPIO_Initialize();
    while(1)
    {
    }
}

void GPIO_Initialize(void){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	GPIO_Output_config(&gpio_int);
	GPIO_Init(GPIOC, &gpio_int);
	GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);

}

void GPIO_Output_config(GPIO_InitTypeDef *GPIO_InitStruct){
	GPIO_InitStruct->GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct->GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct->GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct->GPIO_Speed = GPIO_Speed_2MHz;
}

