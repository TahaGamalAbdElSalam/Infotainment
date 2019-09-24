/*******************************************************************************************************************
 * SOS.c
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 *******************************************************************************************************************/
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "SOS.h"
#include "Timer.h"
#include "CPU.h"
/*******************************************************************************************************************
 * shared global variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * static global variable(s)
 *******************************************************************************************************************/
static SOS_strTask_t SOS_g_strTasks_arr[SOS_NUMBER_OF_TASKS];
/*******************************************************************************************************************
 * ISR & static function prototype(s)
 *******************************************************************************************************************/
static void SOS_vLongTerm(void);
/*******************************************************************************************************************
 * shared function definition(s)
 *******************************************************************************************************************/
/*......................................................................................
 * name:                SOS_vInit
 * description:         initialize the timer and the "global tasks array"
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *......................................................................................*/
SOS_enmStatus_t SOS_enmInit(void)
{
	uint8_t Init_l_u8Counter = DUMMY;
	
	SOS_enmStatus_t Init_l_enmReturnValue = SOS_OK;
	/*........................................*/
#if(SOS_ERROR_DETECT == 1)
	/* check for any error */
	
	/* report the error if any */
	if(Init_l_enmReturnValue != SOS_OK)
	{
		DET_vReportError();
	}
	else
#endif /* (SOS_ERROR_DETECT == 1) */
	/*........................................*/
	{
		for(Init_l_u8Counter = 0u; Init_l_u8Counter < SOS_NUMBER_OF_TASKS; Init_l_u8Counter++)
		{
			SOS_g_strTasks_arr[Init_l_u8Counter].m_enmState = SOS_TASK_STATE_DELETE;
			SOS_g_strTasks_arr[Init_l_u8Counter].m_vCallBackFunction_ptr = NULL_POINTER;
		}
		Timer_enmInit();
	}
	return Init_l_enmReturnValue;
}
/*......................................................................................
 * name:                SOS_vCreateTask
 * description:         initialize a new task,
 *						ses the task "period" and the "callback function"
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     a_enmName	-> name of the task
 *						specified by the user in "SOS_cfg.h"
 *						a_u16Period	-> task period
 *						a_vCallBackFunction_ptr	-> callback function to the task
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *......................................................................................*/
SOS_enmStatus_t SOS_enmCreateTask(SOS_enmTaskName_t a_enmName, uint16_t a_u16Period, void (*a_vCallBackFunction_ptr)(void))
{
	SOS_enmStatus_t CreateTask_l_enmReturnValue = SOS_OK;
	/*........................................*/
#if(SOS_ERROR_DETECT == 1)
	/* check for any error */
	if(a_enmName >= SOS_NUMBER_OF_TASKS)
	{
		CreateTask_l_enmReturnValue = SOS_NOT_OK;
	}
	else if(SOS_g_strTasks_arr[a_enmName].m_vCallBackFunction_ptr != NULL_POINTER)
	{
		CreateTask_l_enmReturnValue = SOS_NOT_OK;
	}
	else if(a_u16Period == 0)
	{
		CreateTask_l_enmReturnValue = SOS_NOT_OK;
	}
	else
	{
		/* do nothing */
	}
	/* report the error if any */
	if(CreateTask_l_enmReturnValue != SOS_OK)
	{
		DET_vReportError();
	}
	else
#endif /* (SOS_ERROR_DETECT == 1) */
	/*........................................*/
	{
		SOS_g_strTasks_arr[a_enmName].m_u16Period = a_u16Period;
		SOS_g_strTasks_arr[a_enmName].m_vCallBackFunction_ptr = a_vCallBackFunction_ptr;
		SOS_g_strTasks_arr[a_enmName].m_enmState = SOS_TASK_STATE_READY;
	}
	return CreateTask_l_enmReturnValue;
}
/*......................................................................................
 * name:                SOS_vDeleteTask
 * description:         disable the task
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     a_enmName	-> name of the task
 *						specified by the user in "SOS_cfg.h"
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *......................................................................................*/
SOS_enmStatus_t SOS_enmDeleteTask(SOS_enmTaskName_t a_enmName)
{
	SOS_enmStatus_t DeleteTask_l_enmReturnValue = SOS_OK;
	/*........................................*/
#if(SOS_ERROR_DETECT == 1)
	/* check for any error */
	if(a_enmName >= SOS_NUMBER_OF_TASKS)
	{
		DeleteTask_l_enmReturnValue = SOS_NOT_OK;
	}
	/* report the error if any */
	if(DeleteTask_l_enmReturnValue != SOS_OK)
	{
		DET_vReportError();
	}
	else
#endif /* (SOS_ERROR_DETECT == 1) */
	/*........................................*/
	{
		SOS_g_strTasks_arr[a_enmName].m_enmState = SOS_TASK_STATE_DELETE;
		SOS_g_strTasks_arr[a_enmName].m_vCallBackFunction_ptr = NULL_POINTER;
	}
	return DeleteTask_l_enmReturnValue;
}
/*......................................................................................
 * name:                SOS_vRun
 * description:         enable the global interrupts,
 *						start the OS
 *						call the ready function starting with the highest priority
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *......................................................................................*/
SOS_enmStatus_t SOS_enmRun(void)
{
	uint8_t Run_l_u8Counter = DUMMY;
	
	SOS_enmStatus_t Run_l_enmReturnValue = SOS_OK;
	/*........................................*/
#if(SOS_ERROR_DETECT == 1)
	/* check for any error */

	/* report the error if any */
	if(Run_l_enmReturnValue != SOS_OK)
	{
		DET_vReportError();
	}
	else
#endif /* (SOS_ERROR_DETECT == 1) */
	/*........................................*/
	{
		SET_BIT(SREG_REG, I_BIT, uint8_t);
		Timer_enmStart(SOS_SYSTEM_TIMER, SOS_SYSTEM_TICK, &SOS_vLongTerm);
		for(;;)
		{
			Run_l_u8Counter = 0u;
			while(Run_l_u8Counter < SOS_NUMBER_OF_TASKS)
			{
				if(SOS_TASK_STATE_READY == SOS_g_strTasks_arr[Run_l_u8Counter].m_enmState)
				{
					SOS_g_strTasks_arr[Run_l_u8Counter].m_vCallBackFunction_ptr();
					SOS_g_strTasks_arr[Run_l_u8Counter].m_enmState = SOS_TASK_STATE_WAIT;

					Run_l_u8Counter = SOS_NUMBER_OF_TASKS;
				}
				Run_l_u8Counter++;
			}
			/* sleep */
			CPU_enmSleep();
		}
	}
	return Run_l_enmReturnValue;
}
/*......................................................................................
 * name:                SOS_vLongTerm
 * description:         change the tasks state to "ready" when it is
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *......................................................................................*/
static void SOS_vLongTerm(void)
{
	static uint16_t LongTerm_l_u16SystemCounter = 0u;
	uint8_t LongTerm_l_u8Counter = DUMMY;
	
	LongTerm_l_u16SystemCounter++;
	for(LongTerm_l_u8Counter = 0u; LongTerm_l_u8Counter < SOS_NUMBER_OF_TASKS; LongTerm_l_u8Counter++)
	{
		switch(SOS_g_strTasks_arr[LongTerm_l_u8Counter].m_enmState)
		{
		case SOS_TASK_STATE_WAIT :
			if(0u == (LongTerm_l_u16SystemCounter % SOS_g_strTasks_arr[LongTerm_l_u8Counter].m_u16Period))
			{
				SOS_g_strTasks_arr[LongTerm_l_u8Counter].m_enmState = SOS_TASK_STATE_READY;
			}
			break;
		default :
			/* do nothing */
			break;
		}
	}
}
/*******************************************************************************************************************
 * ISR & static function definition(s)
 *******************************************************************************************************************/
