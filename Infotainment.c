/*******************************************************************************************************************
 * Infotainment.c
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 *******************************************************************************************************************/
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "Infotainment.h"
#include "Keypad.h"
/*******************************************************************************************************************
 * shared global variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * static global variable(s)
 *******************************************************************************************************************/
static const uint8_t Info_g_u8Questions_arr[INFO_NUMBER_OF_QUESTIONS][INFO_MAX_NUMBER_OF_LETTERS] =
{
	"First Question",
	"Second Question",
	"Third Question",
	"Forth Question",
	"Fifth Question"
};
static const Info_enmAnswer_t Info_g_enmAnswers_arr[INFO_NUMBER_OF_QUESTIONS] = 
{
	INFO_ANSWER_NO,
	INFO_ANSWER_NO,
	INFO_ANSWER_YES,
	INFO_ANSWER_NO,
	INFO_ANSWER_YES
};
/*******************************************************************************************************************
 * ISR & static function prototype(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * shared function definition(s)
 *******************************************************************************************************************/
void Info_vInit(void)
{
	LCD_init();
	Keypad_vInit();
}

extern void Info_vRun(void)
{
	static Info_enmState_t Run_l_enmState = INFO_STATE_QUESTION;
	static Info_enmAnswer_t Run_l_enmAnswer = INFO_ANSWER_NOTHING;
	static uint8_t Run_l_u8QuestionNumber = 0;
	static uint8_t Run_l_u8Score = 0;
	switch(Run_l_enmState)
	{
	case INFO_STATE_QUESTION:
		/* output */
		LCD_displayString(Info_g_u8Questions_arr[Run_l_u8QuestionNumber]);
		/* next state */
		if((Keypad_enmKeyState(KEYPAD_KEY_YES) == BUTTON_STATE_PRESSED) && (Keypad_enmKeyState(KEYPAD_KEY_NO) == BUTTON_STATE_PRESSED))
		{
			Run_l_enmState = INFO_STATE_SCORE;
		}
		else if(Keypad_enmKeyState(KEYPAD_KEY_YES) == BUTTON_STATE_PRESSED)
		{
			Run_l_enmState = INFO_STATE_ANSWER;
			Run_l_enmAnswer = INFO_ANSWER_YES;
		}
		else if(Keypad_enmKeyState(KEYPAD_KEY_NO) == BUTTON_STATE_PRESSED)
		{
			Run_l_enmState = INFO_STATE_ANSWER;
			Run_l_enmAnswer = INFO_ANSWER_NO;
		}
		break;
	case INFO_STATE_ANSWER:
		/* output */
		LCD_Write_Integer_Number(Info_g_enmAnswers_arr[Run_l_u8QuestionNumber]);
		/* next state */
		if(Keypad_enmKeyState(KEYPAD_KEY_NEXT) == BUTTON_STATE_PRESSED)
		{
			if(Run_l_u8QuestionNumber >= INFO_NUMBER_OF_QUESTIONS)
			{
				Run_l_enmState = INFO_STATE_SCORE;
			}
			else
			{
				Run_l_enmState = INFO_STATE_QUESTION;
				if(Run_l_enmAnswer == Info_g_enmAnswers_arr[Run_l_u8QuestionNumber])
				{
					Run_l_u8Score++;
				}
				Run_l_u8QuestionNumber++;
			}
		}
		break;
	case INFO_STATE_SCORE:
		/* output */
		LCD_Write_Integer_Number(Run_l_u8Score);
		/* next state */
		if(Keypad_enmKeyState(KEYPAD_KEY_RESTART) == BUTTON_STATE_PRESSED)
		{
			Run_l_enmState = INFO_STATE_QUESTION;
		}
		break;
	default :
		break;
	}
}
/*******************************************************************************************************************
 * ISR & static function definition(s)
 *******************************************************************************************************************/