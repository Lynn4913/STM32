#include "stm32f10x.h"

uint32_t SystemCoreClock = 72000000;

void SystemInit(void)
{
    SystemCoreClock = 72000000;
}