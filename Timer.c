/*******************************************************************************************************************
 * Timer.c
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

/*******************************************************************************************************************
 * static global variable(s)
 *******************************************************************************************************************/
static void (*vTimer0CallBackFunction_ptr)(void) = NULL_POINTER;
/* to be continued */
static void (*vTimer2CallBackFunction_ptr)(void) = NULL_POINTER;
/*******************************************************************************************************************
 * ISR & static function prototype(s)
 *******************************************************************************************************************/
void __vector_10(void) __attribute__ ((signal, used));
/* to be continued */
void __vector_4(void) __attribute__ ((signal, used));
/*******************************************************************************************************************
 * shared function definition(s)
 *******************************************************************************************************************/
/*......................................................................................
 * name:                Timer_enmInit
 * description:         initialize all the configured timers
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              function state
 * remarks:             none
 * example:             none
 *......................................................................................*/
Timer_enmStatus_t Timer_enmInit(void)
{
    uint8_t Init_l_u8Counter;

    Timer_enmStatus_t Init_l_enmReturnValue = TIMER_OK;
    /*........................................*/
#if(TIMER_ERROR_DETECT == 1)
    /* check for any error */
    for(Init_l_u8Counter = 0u; Init_l_u8Counter < TIMER_NUMBER_OF_TIMERS; Init_l_u8Counter++)
    {
        switch(Timer_enmConfiguration_arr[Init_l_u8Counter])
        {
        case TIMER_NUMBER_0 :
        case TIMER_NUMBER_1 :
        case TIMER_NUMBER_2 :
            break;
        default:
            Init_l_enmReturnValue = TIMER_NOT_OK;
            break;
        }
    }
    /* report the error if any */
    if(Init_l_enmReturnValue != TIMER_OK)
    {
        DET_vReportError();
    }
    else
#endif /* (TIMER_ERROR_DETECT == 1) */
    /*........................................*/
    {
        for(Init_l_u8Counter = 0u; Init_l_u8Counter < TIMER_NUMBER_OF_TIMERS; Init_l_u8Counter++)
        {
            switch(Timer_enmConfiguration_arr[Init_l_u8Counter])
            {
            case TIMER_NUMBER_0 :
                /* Configure the timer control register to CTC mode
                 * for WGM01, WGM00
                 * 0. Normal Mode
                 * 1. PWM, Phase Correct
                 * 2. CTC Mode
                 * 3. Fast PWM
                 */
                CLEAR_BIT(TCCR0_REG, WGM00_BIT, uint8_t);
                SET_BIT(TCCR0_REG, WGM01_BIT, uint8_t);
                break;
            case TIMER_NUMBER_1 :
                /* Configure the timer control register to CTC mode
                 * for WGM13 WGM12 WGM11 WGM10
                 * 0. Normal                            => 0xFFFF
                 * 1. PWM, Phase Correct, 8-bit         => 0x00FF
                 * 2. PWM, Phase Correct, 9-bit         => 0x01FF
                 * 3. PWM, Phase Correct, 10-bit        => 0x03FF
                 * 4. CTC                               => OCR1A
                 * 5. Fast PWM, 8-bit                   => 0x00FF
                 * 6. Fast PWM, 9-bit                   => 0x01FF
                 * 7. Fast PWM, 10-bit                  => 0x03FF
                 * 8. PWM, Phase and Frequency Correct  => ICR1
                 * 9. PWM, Phase and Frequency Correct  => OCR1A
                 * 10. PWM, Phase Correct               => ICR1
                 * 11. PWM, Phase Correct               => OCR1A
                 * 12. CTC                              => ICR1
                 * 13. Reserved
                 * 14. Fast PWM                         => ICR1
                 * 15. Fast PWM                         => OCR1A
                 * input capture                        => working by default for PD6
                 */
                CLEAR_BIT(TCCR1A_REG, WGM10_BIT, uint8_t);
                CLEAR_BIT(TCCR1A_REG, WGM11_BIT, uint8_t);
                SET_BIT(TCCR1B_REG, WGM12_BIT, uint8_t);
                CLEAR_BIT(TCCR1B_REG, WGM13_BIT, uint8_t);
                break;
            case TIMER_NUMBER_2 :
                /* Configure the timer control register to CTC mode
                 * for WGM21, WGM20
                 * 0. Normal Mode
                 * 1. PWM, Phase Correct
                 * 2. CTC Mode
                 * 3. Fast PWM
                 */
                CLEAR_BIT(TCCR2_REG, WGM20_BIT, uint8_t);
                SET_BIT(TCCR2_REG, WGM21_BIT, uint8_t);
                break;
            default:
                /* do nothing */
                break;
            }
        }
    }
    return Init_l_enmReturnValue;
}
/*......................................................................................
 * name:                Timer_enmStart
 * description:         set the callback function
 *						enable interrupt 
 *						start the timer
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     a_enmName	-> timer name specified by the user in "Timer_cfg.h"
 *						a_enmPeriod	-> period for one interrupt
 *						a_vCallBackFunction_ptr	-> callback function to be called in the ISR
 * parameters (inout):  none
 * parameters (out):    none
 * return:              function state
 * remarks:             none
 * example:             none
 *......................................................................................*/
Timer_enmStatus_t Timer_enmStart(Timer_enmName_t a_enmName, Timer_enmPeriod_t a_enmPeriod, void(*a_vCallBackFunction_ptr)(void))
{
    uint16_t Start_l_OutputCompareValue = DUMMY;
    Timer_enmPrescaler_t Start_l_PrescalerValue = (Timer_enmPrescaler_t)DUMMY;

    Timer_enmStatus_t Start_l_enmReturnValue = TIMER_OK;
    /*........................................*/
#if(TIMER_ERROR_DETECT == 1)
    /* check for any error */
#if(MCU_FREQUENCY != 8000000)
    Start_l_enmReturnValue = TIMER_NOT_OK;
#endif /* (MCU_FREQUENCY != 8000000) */
    if(a_vCallBackFunction_ptr == NULL_POINTER)
    {
        Start_l_enmReturnValue = TIMER_NOT_OK;
    }
    else if(a_enmPeriod == TIMER_PERIOD_1_SECOND)
    {
        if(Timer_enmConfiguration_arr[a_enmName] != TIMER_NUMBER_1)
        {
            Start_l_enmReturnValue = TIMER_NOT_OK;
        }
    }
    else
    {
        /* do nothing */
    }
    /* report the error if any */
    if(Start_l_enmReturnValue != TIMER_OK)
    {
        DET_vReportError();
    }
    else
#endif /* (TIMER_ERROR_DETECT == 1) */
    /*........................................*/
    {
        /* calculate output compare and prescaler */
        switch(a_enmPeriod)
        {
        case TIMER_PERIOD_10_MICRO_SECOND:
            Start_l_OutputCompareValue = 80u;
            Start_l_PrescalerValue = TIMER_PRESCALER_CPU_CLOCK;
            break;
        case TIMER_PERIOD_1_MILLI_SECOND:
            Start_l_OutputCompareValue = 125u;
            Start_l_PrescalerValue = TIMER_PRESCALER_64;
            break;
        case TIMER_PERIOD_1_SECOND:
            Start_l_OutputCompareValue = 31250u;
            Start_l_PrescalerValue = TIMER_PRESCALER_256;
            break;
        default:
            /* do nothing */
            break;
        }
        /*
         * 1- set initial value
         * 2- clear interrupt flag (by writing 1 !!)
         * 3- set the callback function
         * 4- enable interrupt
         * 5- set output compare value
         * 6- set prescaler and start the timer
         */
        switch(Timer_enmConfiguration_arr[a_enmName])
        {
        case TIMER_NUMBER_0:
            TCNT0_REG = 0u;
            SET_BIT(TIFR_REG, OCF0_BIT, uint8_t);
            vTimer0CallBackFunction_ptr = a_vCallBackFunction_ptr;
            SET_BIT(TIMSK_REG, OCIE0_BIT, uint8_t);
            OCR0_REG = (uint8_t)Start_l_OutputCompareValue;
            WRITE_REG(TCCR0_REG,
                      (uint8_t)(1u<<CS00_BIT) | (uint8_t)(1u<<CS01_BIT) | (uint8_t)(1u<<CS02_BIT),
                      Start_l_PrescalerValue,
                      uint8_t);
            break;
        case TIMER_NUMBER_1:
            /* to be continued */
            break;
        case TIMER_NUMBER_2:
            TCNT2_REG = 0u;
            SET_BIT(TIFR_REG, OCF2_BIT, uint8_t);
            vTimer2CallBackFunction_ptr = a_vCallBackFunction_ptr;
            SET_BIT(TIMSK_REG, OCIE2_BIT, uint8_t);
            OCR2_REG = (uint8_t)Start_l_OutputCompareValue;
            WRITE_REG(TCCR2_REG,
                      (uint8_t)(1u<<CS20_BIT) | (uint8_t)(1u<<CS21_BIT) | (uint8_t)(1u<<CS22_BIT),
                      Start_l_PrescalerValue,
                      uint8_t);
            break;
        default:
            /* do nothing */
            break;
        }
    }
    return Start_l_enmReturnValue;
}
/*......................................................................................
 * name:                Timer_enmDelayBlocking
 * description:         start the timer and delay the system by bolling on a flag
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     a_enmName	-> timer name specified by the user in "Timer_cfg.h"
 *						a_enmPeriod	-> period for one flag
 *						a_u64Delay	-> delay ammount which is multipules of "a_enmPeriod"
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *......................................................................................*/
Timer_enmStatus_t Timer_enmDelayBlocking(Timer_enmName_t a_enmName, Timer_enmPeriod_t a_enmPeriod, uint64_t a_u64Delay)
{
    volatile uint64_t DelayBlocking_l_u64Counter = DUMMY;
    uint16_t DelayBlocking_l_OutputCompareValue = DUMMY;
    Timer_enmPrescaler_t DelayBlocking_l_PrescalerValue = (Timer_enmPrescaler_t)DUMMY;

    Timer_enmStatus_t DelayBlocking_l_enmReturnValue = TIMER_OK;
    /*........................................*/
    /*
     * error checking
     */
#if(TIMER_ERROR_DETECT == 1)
    /* check for any error */

    /* report the error if any */
    if(DelayBlocking_l_enmReturnValue != TIMER_OK)
    {
        DET_vReportError();
    }
    else
#endif /* (TIMER_ERROR_DETECT == 1) */
    /*........................................*/
    {
        /* calculate output compare and prescaler */
        switch(a_enmPeriod)
        {
        case TIMER_PERIOD_10_MICRO_SECOND:
            DelayBlocking_l_OutputCompareValue = 80u;
            DelayBlocking_l_PrescalerValue = TIMER_PRESCALER_CPU_CLOCK;
            break;
        case TIMER_PERIOD_1_MILLI_SECOND:
            DelayBlocking_l_OutputCompareValue = 250u;
            DelayBlocking_l_PrescalerValue = TIMER_PRESCALER_64;
            break;
        case TIMER_PERIOD_1_SECOND:
            DelayBlocking_l_OutputCompareValue = 31250u;
            DelayBlocking_l_PrescalerValue = TIMER_PRESCALER_256;
            break;
        default:
            /* do nothing */
            break;
        }
        /*
         * 1- set initial value
         * 2- clear interrupt flag (by writing 1 !!)
         * 3- set output compare value
         * 4- set prescaler and start the timer
         * 5- wait for flag to rise
         * 6- clear flag (by writing 1 !!)
         * 7- update counter and loop
         * 8- stop the timer
         */
        switch(Timer_enmConfiguration_arr[a_enmName])
        {
        case TIMER_NUMBER_0:
            TCNT0_REG = 0u;
            SET_BIT(TIFR_REG, OCF0_BIT, uint8_t);
            OCR0_REG = (uint8_t)DelayBlocking_l_OutputCompareValue;
            WRITE_REG(TCCR0_REG,
                      (uint8_t)(1u<<CS00_BIT) | (uint8_t)(1u<<CS01_BIT) | (uint8_t)(1u<<CS02_BIT),
                      DelayBlocking_l_PrescalerValue,
                      uint8_t);
            for(DelayBlocking_l_u64Counter = 0u; DelayBlocking_l_u64Counter < a_u64Delay; DelayBlocking_l_u64Counter++)
            {
                while(GET_BIT(TIFR_REG, OCF0_BIT, uint8_t) == 0u);
                SET_BIT(TIFR_REG, OCF0_BIT, uint8_t);
            }
            WRITE_REG(TCCR0_REG,
                      (uint8_t)(1u<<CS00_BIT) | (uint8_t)(1u<<CS01_BIT) | (uint8_t)(1u<<CS02_BIT),
                      TIMER_PRESCALER_NO_CLOCK,
                      uint8_t);
            break;
        case TIMER_NUMBER_1:
            /* to be continued */
            break;
        case TIMER_NUMBER_2:
            TCNT2_REG = 0u;
            SET_BIT(TIFR_REG, OCF2_BIT, uint8_t);
            OCR2_REG = (uint8_t)DelayBlocking_l_OutputCompareValue;
            WRITE_REG(TCCR2_REG,
                      (uint8_t)(1u<<CS20_BIT) | (uint8_t)(1u<<CS21_BIT) | (uint8_t)(1u<<CS22_BIT),
                      DelayBlocking_l_PrescalerValue,
                      uint8_t);
            for(DelayBlocking_l_u64Counter = 0u; DelayBlocking_l_u64Counter < a_u64Delay; DelayBlocking_l_u64Counter++)
            {
                while(GET_BIT(TIFR_REG, OCF2_BIT, uint8_t) == 0u);
                SET_BIT(TIFR_REG, OCF2_BIT, uint8_t);
            }
            WRITE_REG(TCCR2_REG,
                      (uint8_t)(1u<<CS20_BIT) | (uint8_t)(1u<<CS21_BIT) | (uint8_t)(1u<<CS22_BIT),
                      TIMER_PRESCALER_NO_CLOCK,
                      uint8_t);
            break;
        default:
            /* do nothing */
            break;
        }
    }
    return DelayBlocking_l_enmReturnValue;
}
/*******************************************************************************************************************
 * ISR & static function definition(s)
 *******************************************************************************************************************/
/*......................................................................................
 * name:                __vector_10
 * description:         ISR for timer0 compare match
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *......................................................................................*/
void __vector_10(void)
{
    vTimer0CallBackFunction_ptr();
}
/* ISR for timer1 compare match */
/* to be continued */
/*......................................................................................
 * name:                __vector_4
 * description:         ISR for timer2 compare match
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *......................................................................................*/
void __vector_4(void)
{
    vTimer2CallBackFunction_ptr();
}
