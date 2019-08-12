#include "key.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "delay.h"

void Key_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOE, ENABLE);
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_3;
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_4;
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	
}

u8 key_scan(u8 mode)
{
	
	static u8 key_up=1;
	if(mode==1)
	{
		key_up=1;
	}
	if(key_up==1&&(KEY0==0||KEY1==0||KEY_WKUP==1))
	{
		delay_ms(10);
		key_up=0;
		if(KEY0==0)
		{
			return KEY0_1;
		}
		if(KEY1==0)
		{
			return KEY1_2;
		}
		if(KEY_WKUP==1)
		{
			return KEYUP_3;
		}
	}else if(KEY0==1||KEY1==1||KEY_WKUP==0)
	{
		key_up=1;
	}
	return 0;
}

