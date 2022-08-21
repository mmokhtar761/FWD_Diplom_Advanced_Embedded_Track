/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
 *        \brief  
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "00- Mcu_Hw.h"
#include "SysTick.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
/*
#define SINGLE_SHOT_ONLY
#define SINGLE_SHOT_NOTF
#define MULTI_SHOT_NOTF
#define MULTI_SHOT_NOTF
*/
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint8 OneShotFlag;
static uint8 SysTickNotfFlag;
static void (*SysTickCallBackFb)(void);
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 /******************************************************************************
* \Syntax          :                    
* \Description     : i
*                    i                            
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTickStartMultiShot (SysTickCount_type CopyRldVal)
{
	if (CopyRldVal > SYS_TICK_MAX_VAL) return;/*TO DO : return error*/
	/*Flagging that multi shot is needed*/
	OneShotFlag = 0; 
	/*Choose clk source as configured*/
	#if     SYS_TICK_CLK_SOURCE == SYS_CLK 
	BIT_H(MY_SYS_TICK->STCTRL,2);
	#elif SYS_TICK_CLK_SOURCE == PIOSC_DIV_4 
	BIT_L(MY_SYS_TICK->STCTRL,2);
	#endif
	/*writing the start value in the reload reg*/
	MY_SYS_TICK->STRELOAD  = CopyRldVal;
	/*Writing to the timer counting register to clear it and clear any perivious flags (COUNT bit and interrupt)*/
	MY_SYS_TICK->STCURRENT = CopyRldVal;
	/*start the timer*/
	BIT_H(MY_SYS_TICK->STCTRL,0);
}
void SysTickStartOneShot   (SysTickCount_type CopyRldVal)
{
	/*Calling the multi shot as almost same actions is needed*/
	SysTickStartMultiShot (CopyRldVal);
	/*editing the flag to shot only one instance*/
	OneShotFlag = 1; 
	/*enabling interrupt to stop the timer in*/
	BIT_H(MY_SYS_TICK->STCTRL,1);
}
void SysTickStop           (void)
{
	/*pause the timer counting*/
	BIT_L(MY_SYS_TICK->STCTRL,0);
}
SysTickCount_type SysTick_CountGetElpsd  (void)
{
	/*Getting the elapsed counts*/
	return (SysTickCount_type)(MY_SYS_TICK->STRELOAD - MY_SYS_TICK->STCURRENT);
}
SysTickCount_type SysTick_CountGetRemn   (void)
{
	/*Getting the current counts to reach zero*/
	return (SysTickCount_type)(MY_SYS_TICK->STCURRENT);
}
void SysTickEnNotf         (void(*PtrCallBackFn)(void))
{
	/*setting the call back function*/
	SysTickCallBackFb = PtrCallBackFn;
	/*Flagging that a call to the call-back funcion is needed*/
	SysTickNotfFlag = 1;
	/*Enable the interrupt*/
	BIT_H(MY_SYS_TICK->STCTRL,1);
}
void SysTickDisNotf        (void)
{
	/*disabling the interrupt*/
	BIT_L(MY_SYS_TICK->STCTRL,1);
	/*Clearing the nofication flag*/
	SysTickNotfFlag = 0;
}
void SysTick_Handler (void)
{
	if (SysTickNotfFlag) SysTickCallBackFb();
	if (OneShotFlag) 
	{
		/*clearing the flag and disabling the timer as the shot has alredy done*/
		OneShotFlag = 0;
		BIT_L(MY_SYS_TICK->STCTRL,0);
		/*disabling the interrupt*/
		BIT_L(MY_SYS_TICK->STCTRL,1);
		/*Clearing the nofication flag*/
		SysTickNotfFlag = 0;
	}
	
	
}

/**********************************************************************************************************************
 *  END OF FILE: SysTick.c
 *********************************************************************************************************************/
