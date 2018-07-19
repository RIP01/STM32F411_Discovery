#include "stm32f4xx.h"

GPIO_InitTypeDef  GPIO_InitStructure;
void GPIO_Configuration(void);
void Delay(__IO uint32_t nCount);

int main(void)
{			
		GPIO_Configuration();
		while (1)
		{		
				
		}
}

void GPIO_Configuration(void)
{
	
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

