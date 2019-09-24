#ifndef DIO_H_
#define DIO_H_
/* include(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
#include "CommonHeaders.h"
#include "DIO_Reg.h"
#include "ATMega32MemMapReg.h"
/* definition(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
#define DIO_NUMBER_OF_ALL_PINS	(32)
#define DIO_NUMBER_OF_PORT_PINS	(8)
enum DIO_PIN 
{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
};
enum DIO_PORT 
{
	DIO_PORTA, 
	DIO_PORTB, 
	DIO_PORTC, 
	DIO_PORTD
};
enum DIO_DIR
{
	DIO_DIR_IN,
	DIO_DIR_OUT
};
enum DIO_LEVEL
{
	DIO_LEVEL_LOW,
	DIO_LEVEL_HIGH
};
#define DIO_LEVEL_ALL_LOW	(0)
#define DIO_LEVEL_ALL_HIGH	(~0)
/* type definition(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
typedef struct 
{
	volatile uint8_t* DirRegAddr;
	volatile uint8_t* PortRegAddr;
	volatile const uint8_t* PinRegAddr;
	volatile uint8_t PinIndex;
}DIO_PinType;
/* external variable(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

/* external function prototype(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*..................................................................................
 * name:                DIO_Init
 * description:         initialize all global variables of the DIO module
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
extern void DIO_Init(void);
/*..................................................................................
 * name:                DIO_SetPinDirection
 * description:         set the direction of a specified pin
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     PinNum			=>	pin ID, where the pins in all ports
 *											are serializes
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
extern void DIO_SetPinDirection(uint8_t PinNum, uint8_t PinDirection);
/*..................................................................................
 * name:                DIO_ReadPin
 * description:         return the value of a specified pin
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     PinNum			=>	pin ID, where the pins in all ports
 *											are serializes
 * parameters (inout):  none
 * parameters (out):    none
 * return:              value of a specified pin
 * remarks:             none
 * example:             none
 *..................................................................................*/
extern uint8_t DIO_ReadPin(uint8_t PinNum);
/*..................................................................................
 * name:                DIO_WritePin
 * description:         set the level of a specified pin
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     PinNum			=>	pin ID, where the pins in all ports 
 *											are serializes
						PinValue		=>	low or high
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
extern void DIO_WritePin(uint8_t PinNum, uint8_t PinValue);
/*..................................................................................
 * name:                DIO_FlipPin
 * description:         flip the level of a specified pin
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     PinNum			=>	pin ID, where the pins in all ports 
 *											are serializes
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
extern void DIO_FlipPin(uint8_t PinNum);
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
#endif /* DIO_H_ */