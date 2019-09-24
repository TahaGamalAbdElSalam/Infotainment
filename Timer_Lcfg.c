/*******************************************************************************************************************
 * Timer_Lcfg.c
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 *******************************************************************************************************************/
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "Timer.h"
/*******************************************************************************************************************
 * shared global variable(s)
 *******************************************************************************************************************/
/*..................................................................................
 * name:            Timer_strConfiguration_arr
 * description:     array of configuration structures for Timer module
 * members:         m_enmNumber -> number of the timer
 *..................................................................................*/
const Timer_enmNumber_t Timer_enmConfiguration_arr[TIMER_NUMBER_OF_TIMERS] =
{
    /* write the configuration below */
    TIMER_NUMBER_0,
    TIMER_NUMBER_2
    /* write the configuration above */
};
/*******************************************************************************************************************
 * static global variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * ISR & static function prototype(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * shared function definition(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * ISR & static function definition(s)
 *******************************************************************************************************************/