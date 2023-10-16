#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include"RCC_Interface.h"
#include"GPIO_Interface.h"
//#include"NVIC_Interface.h"
#include "MDAC_Interface.h"
#include"STK_Interface.h"
//#include"EXTI_Interface.h"
#include"USART_Interface.h"
//#include"EXTI_Interface.h"
//#include"FreeRTOS.h"
//#include"semphr.h"
//#include"task.h"





int main()
{

	RCC_voidInitSysClk();
	RCC_voidEnablePeripheralClk(AHB1, 0);//PORTA
	RCC_voidEnablePeripheralClk(AHB1, 1);//PORTB
	RCC_voidEnablePeripheralClk(APB2, 4);//PORTB
    STK_voidInit();
   u8 i=0;
    for(i=0;i<6;i++)
    {

    GPIO_voidSetPinMode(IOA, i,OUTPUT);
    GPIO_voidSetPinType(IOA, i, OUTPUT_PP);
    GPIO_voidSetPinSpeed(IOA,i,OUTPUT_LS) ;
    }
    GPIO_voidSetPinMode(IOA, PIN9,AF);
    GPIO_voidSetPinMode(IOA, PIN10,AF);

    set_altetnate_func(IOA,PIN9,7);
    set_altetnate_func(IOA,PIN10,7);
    USART_voidInit();

  //  USART_voidSend(x,3);
    u8 y;
   // USART_voidReceive(y);



 while(1)
	{
	 USART_voidReceive(&y);
	 //USART_voidSend(y,1);


	if(y=='1')
	 {
	 GPIO_voidSetPinValue(IOA, PIN0, HIGH);
	 GPIO_voidSetPinValue(IOA, PIN2, HIGH);
	 GPIO_voidSetPinValue(IOA, PIN3, LOW);

	 }

	}
}







