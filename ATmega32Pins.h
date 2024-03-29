#ifndef ATMEGA32PINS_H_
#define ATMEGA32PINS_H_
/* include(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

/* definition(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
enum ATMEGA32_PINS
{
	PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7,
	PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7,
	PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7,
	PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7
};

#define PIN_ICP					PD6
#define PIN_OC0					PB3

#define SPRINTS_LED0			PB4
#define SPRINTS_LED1			PB5
#define SPRINTS_LED2			PB6
#define SPRINTS_LED3			PB7

#define SPRINTS_BUTTON0			PC4

#define SPRINTS_ROW_1			PC2
#define SPRINTS_ROW_2			PC3
#define SPRINTS_ROW_3			PC4
#define SPRINTS_COLUMN_1		PC5
#define SPRINTS_COLUMN_2		PC6
#define SPRINTS_COLUMN_3		PC7

#define SPRINTS_MOTOR_EN1		PD4
#define SPRINTS_MOTOR_DIR1A		PD2
#define SPRINTS_MOTOR_DIR1B		PD3
#define SPRINTS_MOTOR_EN2		PD5
#define SPRINTS_MOTOR_DIR2A		PD6
#define SPRINTS_MOTOR_DIR2B		PD7
/* type definition(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

/* external variable(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

/* external function prototype(s) XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
#endif /* ATMEGA32PINS_H_ */