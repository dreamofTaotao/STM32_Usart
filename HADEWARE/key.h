#ifndef __KEY_H
#define __KEY_H

#include "sys.h"

#define KEY0 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)
#define KEY0_1 1

#define KEY1 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
#define KEY1_2 2

#define KEY_WKUP GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)
#define KEYUP_3 3


void Key_Init(void);
u8 key_scan(u8);

#endif
