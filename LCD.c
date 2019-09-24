 /*******************************************************************************
 *                      	Included Libraries                                 *
 *******************************************************************************/
#include "LCD.h"
#include "DIO_Map.h"
#include "DIO_version2.h"
/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*******************************************************************************
 * Function Name:	LCD_init
 *
 * Description: 	
 * 			
 * Inputs:			
 *
 * Outputs:			
 *
 * Return:			
 *******************************************************************************/
void LCD_init (void){
	/* Data Direction Configuration */
	DIO_DDRA = 0xFF;
	_delay_us(50);
	
	/* Initialize LCD to work in 4_bit mode */
	LCD_sendCommand(Init_4bit_1);
	_delay_us(50);
	LCD_sendCommand(Init_4bit_2);
	_delay_us(50);
	LCD_sendCommand(FunctionSet4bit);
	_delay_us(50);
	
	/* LCD Initialization */
	LCD_sendCommand(Return_home); /* Start from home Position */
	_delay_us(50);
	LCD_sendCommand(Displayon_Cursoroff);  /* LCD display On */
	_delay_us(50);
	LCD_sendCommand(Display_noshift); /*  mode set */
	_delay_us(50);	
	LCD_sendCommand(Clear_display); /* Clear LCD display */
	_delay_us(2000);
}

/*******************************************************************************
 * Function Name:	LCD_sendCommand
 *
 * Description: 	
 * 			
 * Inputs:			
 *
 * Outputs:			
 *
 * Return:			
 *******************************************************************************/
void LCD_sendCommand(uint8_t command){
	/* Control Signals Configuration */
	DIO_WritePin(Register_Select,LOW);  /* Select instruction register */
	DIO_WritePin(Read_Write,LOW);		/* Write operation */
	DIO_WritePin(Enable_LCD,HIGH);		/* Enable Signal */
	_delay_us(50);
	
	/* Sending High nibble */
	DIO_PORTA = (DIO_PORTA & 0x0F) | (command & 0xF0);
	_delay_us(50);
	DIO_WritePin(Enable_LCD,LOW);       /* Disable Signal */
	_delay_us(50);
	DIO_WritePin(Enable_LCD,HIGH);		/* Enable Signal */
	_delay_us(50);
	
	/* Sending Low nibble */
	DIO_PORTA = (DIO_PORTA & 0x0F) | ((command & 0x0F) << 4 );
	_delay_us(50);
	DIO_WritePin(Enable_LCD,LOW);       /* Disable Signal */
	_delay_us(50);
	DIO_WritePin(Enable_LCD,HIGH);		/* Enable Signal */
	_delay_us(50);
}

/*******************************************************************************
 * Function Name:	LCD_displayChar
 *
 * Description: 	
 * 			
 * Inputs:			
 *
 * Outputs:			
 *
 * Return:			
 *******************************************************************************/
void LCD_displayChar(uint8_t character){
	/* Control Signals Configuration */
	DIO_WritePin(Register_Select,HIGH);  /* Select data register */
	DIO_WritePin(Read_Write,LOW);		/* Write operation */
	DIO_WritePin(Enable_LCD,HIGH);		/* Enable Signal */
	_delay_us(50);
	
	/* Sending High nibble */
	DIO_PORTA = (DIO_PORTA & 0x0F) | (character & 0xF0);
	_delay_us(50);
	DIO_WritePin(Enable_LCD,LOW);       /* Disable Signal */
	_delay_us(50);
	DIO_WritePin(Enable_LCD,HIGH);		/* Enable Signal */
	_delay_us(50);
	
	/* Sending low nibble */
	DIO_PORTA = (DIO_PORTA & 0x0F) | ((character & 0x0F) << 4 );
	_delay_us(50);
	DIO_WritePin(Enable_LCD,LOW);       /* Disable Signal */
	_delay_us(50);
	DIO_WritePin(Enable_LCD,HIGH);		/* Enable Signal */
	_delay_us(50);
}

/*******************************************************************************
 * Function Name:	LCD_gotoRowColumn
 *
 * Description: 	
 * 			
 * Inputs:			
 *
 * Outputs:			
 *
 * Return:			
 *******************************************************************************/
void LCD_gotoRowColumn(uint8_t LINE,uint8_t COLUMN){
	if ( ( COLUMN > COLUMN_MIN ) && ( COLUMN <= COLUMN_MAX ) ){
		switch (LINE)
		{
			case LINE_1 :	LCD_sendCommand( ( lcd_line_1_address ) + ( COLUMN ) );
							break;
							
			case LINE_2 :	LCD_sendCommand( ( lcd_line_2_address ) + ( COLUMN ) );
							break;
							
			default :		break;
		}
	}else{
		/* Do Nothing */
	}

}

/*******************************************************************************
 * Function Name:	LCD_displayString
 *
 * Description: 	
 * 			
 * Inputs:			
 *
 * Outputs:			
 *
 * Return:			
 *******************************************************************************/
void LCD_displayString(uint8_t string[]){
	uint8_t iterator = 0;
	while(string[iterator] != '\0')
	{
		LCD_displayChar(string[iterator]);
		iterator++;
	}
}

/*******************************************************************************
 * Function Name:	LCD_displayStringRowColumn
 *
 * Description: 	
 * 			
 * Inputs:			
 *
 * Outputs:			
 *
 * Return:			
 *******************************************************************************/
void LCD_displayStringRowColumn(uint8_t string[],uint8_t row, uint8_t column){
	LCD_gotoRowColumn(row,column);
	LCD_displayString(string);
}


/*******************************************************************************
 * Function Name:	LCD_clear
 *
 * Description: 	
 * 			
 * Inputs:			
 *
 * Outputs:			
 *
 * Return:			
 *******************************************************************************/
void LCD_clear(void){
	LCD_sendCommand(Clear_display);
	_delay_us(2000);
	LCD_sendCommand(Return_home);
}
