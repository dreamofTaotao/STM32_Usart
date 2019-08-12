#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "led.h"
#include "delay.h"
#include "buzzer.h"
#include "key.h"
#include "usart.h"


int main(void)
{
	u16 t;  
	u16 len;	
	u8 res;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
	Led_Init();
	delay_init();
	Buzzer_Init();
	Key_Init();
	LED0=1;
	LED1=0;
	while(1)
	{
		if(USART_RX_STA&0x8000)
		{					   
			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			printf("\r\n您发送的消息为:\r\n\r\n");
			for(t=0;t<len;t++)
			{
				USART_SendData(USART1, USART_RX_BUF[t]);//向串口1发送数据
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
			}
			printf("\r\n\r\n");//插入换行
			USART_RX_STA=0;
		}
	}
}

