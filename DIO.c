/* include(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
#include "DIO.h"
/* shared global variable(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

/* static global variable(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
static volatile DIO_PinType channel[DIO_NUMBER_OF_ALL_PINS];
/* static function prototype(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

/* function definition(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void DIO_Init(void)
{
	uint8_t i;
	for(i=0; i<DIO_NUMBER_OF_ALL_PINS; i++)
	{
		switch(i/DIO_NUMBER_OF_PORT_PINS)
		{
			case DIO_PORTA:
				channel[i].PortRegAddr = (uint8_t*) PORTA_ADDR;
				channel[i].PinRegAddr = (uint8_t*) PINA_ADDR;
				channel[i].DirRegAddr = (uint8_t*) DDRA_ADDR;
			break;
			case DIO_PORTB:
				channel[i].PortRegAddr = (uint8_t*) PORTB_ADDR;
				channel[i].PinRegAddr = (uint8_t*) PINB_ADDR;
				channel[i].DirRegAddr = (uint8_t*) DDRB_ADDR;
			break;
			case DIO_PORTC:
				channel[i].PortRegAddr = (uint8_t*) PORTC_ADDR;
				channel[i].PinRegAddr = (uint8_t*) PINC_ADDR;
				channel[i].DirRegAddr = (uint8_t*) DDRC_ADDR;
			break;
			case DIO_PORTD:
				channel[i].PortRegAddr = (uint8_t*) PORTD_ADDR;
				channel[i].PinRegAddr = (uint8_t*) PIND_ADDR;
				channel[i].DirRegAddr = (uint8_t*) DDRD_ADDR;
			break;
		}
		channel[i].PinIndex = i%DIO_NUMBER_OF_PORT_PINS;
	}
}
void DIO_SetPinDirection(uint8_t PinNum,uint8_t PinDirection)
{
	if(DIO_DIR_IN == PinDirection)
	{
		CLEAR_BIT(*(channel[PinNum].DirRegAddr), (channel[PinNum].PinIndex), uint8_t);
	}
	else if(DIO_DIR_OUT == PinDirection)
	{
		SET_BIT(*(channel[PinNum].DirRegAddr), (channel[PinNum].PinIndex), uint8_t);
	}
}
uint8_t DIO_ReadPin(uint8_t PinNum)
{
	return GET_BIT(*(channel[PinNum].PinRegAddr), (channel[PinNum].PinIndex), uint8_t);
}
void DIO_WritePin(uint8_t PinNum,uint8_t PinValue)
{
	if(DIO_LEVEL_LOW == PinValue)
	{
		CLEAR_BIT(*(channel[PinNum].PortRegAddr), (channel[PinNum].PinIndex), uint8_t);
	}
	else if(DIO_LEVEL_HIGH == PinValue)
	{
		SET_BIT(*(channel[PinNum].PortRegAddr), (channel[PinNum].PinIndex), uint8_t);
	}
}
void DIO_FlipPin(uint8_t PinNum)
{
	if(DIO_LEVEL_LOW == DIO_ReadPin(PinNum))
	{
		DIO_WritePin(PinNum, DIO_LEVEL_HIGH);
	}
	else
	{
		DIO_WritePin(PinNum, DIO_LEVEL_LOW);
	}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/