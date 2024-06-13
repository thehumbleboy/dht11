#include "stm32f4xx.h"
#include "clockconfig.h"


int main(void)
{
	PLL_Config();
	SystemCoreClockUpdate();

    while(1)
    {
    }
}
