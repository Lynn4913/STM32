#include "key.h"
#include "delay.h"  // ?????????(???? delay.c ??)

void Key_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // ??GPIOB??

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 |
                                  GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;  // ????(???VCC)  // ????(???GND)
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint8_t Key_Scan(void)
{
    uint8_t key_val = 0;

    // ???????????
    if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1) key_val = 1;
    else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_2) == 1) key_val = 2;
    else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3) == 1) key_val = 3;
    else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4) == 1) key_val = 4;
    else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 1) key_val = 5;
    else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == 1) key_val = 6;
    else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7) == 1) key_val = 7;

    if(key_val != 0)  // ????????
    {
        delay_ms(20);  // ????(??)

        // ?????????(??????)
        if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1 && key_val == 1) key_val = 1;
        else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_2) == 1 && key_val == 2) key_val = 2;
        else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3) == 1 && key_val == 3) key_val = 3;
        else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4) == 1&& key_val == 4) key_val = 4;
        else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 1 && key_val == 5) key_val = 5;
        else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == 1 && key_val == 6) key_val = 6;
        else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7) == 1&& key_val == 7) key_val = 7;
        else key_val = 0;  // ????,?????

        // ??????(???????????????)
        while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) && key_val == 1);
        while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_2) && key_val == 2);
        while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3) && key_val == 3);
        while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4) && key_val == 4);
        while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) && key_val == 5);
        while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) && key_val == 6);
        while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7) && key_val == 7);
    }

    return key_val;
}