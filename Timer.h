/*******************************************************************************************************************
 * Timer.h
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 *******************************************************************************************************************/
#ifndef TIMER_H_
#define TIMER_H_
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "CommonHeaders.h"
#include "Timer_cfg.h"
/*******************************************************************************************************************
 * definition(s)
 *******************************************************************************************************************/
typedef enum
{
    TIMER_OK,
    TIMER_NOT_OK
}Timer_enmStatus_t;
typedef enum
{
    TIMER_NUMBER_0,
    TIMER_NUMBER_1,
    TIMER_NUMBER_2
}Timer_enmNumber_t;
typedef enum
{
    TIMER_PERIOD_10_MICRO_SECOND,
    TIMER_PERIOD_1_MILLI_SECOND,
    TIMER_PERIOD_1_SECOND
}Timer_enmPeriod_t;
typedef enum
{
    TIMER_INTERRUPT_ENABLED,
    TIMER_INTERRUPT_DISABLED
}Timer_enmInterrupt_t;
typedef enum
{
    TIMER_PRESCALER_NO_CLOCK,
    TIMER_PRESCALER_CPU_CLOCK,
    TIMER_PRESCALER_8,
    TIMER_PRESCALER_64,
    TIMER_PRESCALER_256,
    TIMER_PRESCALER_1024
}Timer_enmPrescaler_t;
/*******************************************************************************************************************
 * type definition(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * external variable(s)
 *******************************************************************************************************************/
extern const Timer_enmNumber_t Timer_enmConfiguration_arr[TIMER_NUMBER_OF_TIMERS];
/*******************************************************************************************************************
 * external function prototype(s)
 *******************************************************************************************************************/
extern Timer_enmStatus_t Timer_enmInit(void);
extern Timer_enmStatus_t Timer_enmStart(Timer_enmName_t a_enmName, Timer_enmPeriod_t a_enmPeriod, void(*a_vCallBackFunction_ptr)(void));
extern Timer_enmStatus_t Timer_enmDelayBlocking(Timer_enmName_t a_enmName, Timer_enmPeriod_t a_enmPeriod, uint64_t a_u64Delay);
#endif /* TIMER_H_ */
