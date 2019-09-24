#ifndef LCD_H_
#define LCD_H_
 
 /*******************************************************************************
 *                      	Included Libraries                                 *
 *******************************************************************************/
#include "DIO_version2.h"
#include "ATmega32Pins.h"
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <util/delay.h>

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define Clear_display 0x01
#define Return_home 0x02
#define Display_noshift 0x06
#define Display_shift 0x07
#define Display_off 0x08
#define Displayon_Cursoroff	0x0C
#define Display_on 0x0E
#define Init_4bit_1 0x33
#define Init_4bit_2 0x32
#define FunctionSet4bit 0x28
#define FunctionSet8bit 0x38
#define SET_CGRAM_addr 0x40
#define SET_DDRAM_addr 0x80
 
#define Register_Select PA1 
#define Read_Write PA2
#define Enable_LCD PA3

#define lcd_line_1_address  0x7F       
#define lcd_line_2_address  0xBF       

#define LINE_1      1
#define LINE_2      2

#define COLUMN_MIN   0
#define COLUMN_MAX   16

 /*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
 void LCD_init (void);
 void LCD_sendCommand(uint8_t command);
 void LCD_displayChar(uint8_t character);
 void LCD_displayString(uint8_t string[]);
 void LCD_displayStringRowColumn(uint8_t string[],uint8_t row, uint8_t column);
 void LCD_gotoRowColumn(uint8_t LINE,uint8_t COLUMN);
 void LCD_clear(void);


#endif /* LCD_H_ */