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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
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
			len=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
			printf("\r\n�����͵���ϢΪ:\r\n\r\n");
			for(t=0;t<len;t++)
			{
				USART_SendData(USART1, USART_RX_BUF[t]);//�򴮿�1��������
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
			}
			printf("\r\n\r\n");//���뻻��
			USART_RX_STA=0;
		}
	}
}

