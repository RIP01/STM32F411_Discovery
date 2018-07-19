#include "stm32f4xx.h"

GPIO_InitTypeDef  GPIO_InitStructure;
void GPIO_Configuration(void);
void Delay(__IO uint32_t nCount);

int main(void)
{			
		GPIO_Configuration();
		GPIO_ResetBits(GPIOD,GPIO_Pin_12| GPIO_Pin_13|GPIO_Pin_14 | GPIO_Pin_15 );
		while (1)
		{		
				//GPIO_SetBits(GPIOD,GPIO_Pin_12| GPIO_Pin_13|GPIO_Pin_14 | GPIO_Pin_15);
				GPIO_Write(GPIOD,0x1000);
				Delay(1000000);
				GPIO_Write(GPIOD,0x2000);
				Delay(1000000);
				GPIO_Write(GPIOD,0x4000);
				Delay(1000000);
				GPIO_Write(GPIOD,0x8000);
				Delay(1000000);
		}
}

void GPIO_Configuration(void)
{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOA, ENABLE);
		/* Configure PB0 PB1 in output pushpull mode */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13|GPIO_Pin_14 | GPIO_Pin_15;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
		GPIO_Init(GPIOD, &GPIO_InitStructure);
		/* Configure PA0 in input mode */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
}
void Delay(__IO uint32_t nCount)
{
		while(nCount--)
		{
		}
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

