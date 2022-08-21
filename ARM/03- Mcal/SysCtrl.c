/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "00- Mcu_Hw.h"
#include "SysCtrl.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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
* \Syntax          : void SysCtrl_VoidInit(void)                                   
* \Description     : initialize System clock parsing the Configuration 
*                    into SysCtrl registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysCtrl_VoidInit(void)
{
	
	/*selecting oscilator source*/
	MY_SYSCTRL->RCC = (MY_SYSCTRL->RCC&((uint32)~0x3<<4))    | (PRIM_CLK_SOURCE<<4);
	
	#if     PRIM_CLK_SOURCE == PIOSC || PRIM_CLK_SOURCE == PIOSC_DIV_4
		/*Assigning OSC freq code oscilator source*/
		MY_SYSCTRL->RCC = (MY_SYSCTRL->RCC&((uint32)~0x1F <<6)) | (PIOSC_OSC_FRQ_CODE<<6);
	#elif     PRIM_CLK_SOURCE == MOSCDIS
		/*The main oscillator enable*/
		BIT_L(MY_SYSCTRL->RCC,0);
	#endif
	
	#if EN_PLL == ENABLE
		/*Powring up the PLL*/	
		BIT_L(MY_SYSCTRL->RCC,13);
		/*Wait PLL to power up*/
		while (!GET_BIT(MY_SYSCTRL->PLLSTAT,0));
		/*Clearing ByPass to use PLL output as system clk*/
		BIT_L(MY_SYSCTRL->RCC,11);
		/*if using PLL, div is forced*/
		#if SYS_DIV < 3
				#error "PLL must be devided by 3 or more"
		#endif
	#endif
	
	#if SYS_DIV == 1 && EN_PLL != ENABLE
		/*Disable division*/
		BIT_L(MY_SYSCTRL->RCC,(uint32)22);
	#else
		/*En division*/
		BIT_H(MY_SYSCTRL->RCC,22);
		/*Setting devision value*/
		MAN_NIBBLE(MY_SYSCTRL->RCC,24,(SYS_DIV-1));
	#endif
	#if     PWM_DIV == 1
		/*disable pwm devision*/
		BIT_L(MY_SYSCTRL->RCC,20);
	#elif PWM_DIV == 2  
		/*enable pwm devision*/
		BIT_H(MY_SYSCTRL->RCC,20);
		/*Assign devision factor*/
		BIT_L(MY_SYSCTRL->RCC,17);
		BIT_L(MY_SYSCTRL->RCC,18);
		BIT_L(MY_SYSCTRL->RCC,19);
	#elif PWM_DIV == 4
		/*enable pwm devision*/
		BIT_H(MY_SYSCTRL->RCC,20);
		/*Assign devision factor*/
		BIT_H(MY_SYSCTRL->RCC,17);
		BIT_L(MY_SYSCTRL->RCC,18);
		BIT_L(MY_SYSCTRL->RCC,19);	
	#elif PWM_DIV == 8
		/*enable pwm devision*/
		BIT_H(MY_SYSCTRL->RCC,(uint32)20);
		/*Assign devision factor*/
		BIT_L(MY_SYSCTRL->RCC,(uint32)17);
		BIT_H(MY_SYSCTRL->RCC,(uint32)18);
		BIT_L(MY_SYSCTRL->RCC,(uint32)19);
	#elif PWM_DIV == 16
		/*enable pwm devision*/
		BIT_H(MY_SYSCTRL->RCC,20);
		/*Assign devision factor*/
		BIT_H(MY_SYSCTRL->RCC,(uint32)17);
		BIT_H(MY_SYSCTRL->RCC,(uint32)18);
		BIT_L(MY_SYSCTRL->RCC,(uint32)19);
	#elif PWM_DIV == 32
		/*enable pwm devision*/
		BIT_H(MY_SYSCTRL->RCC,20);
		/*Assign devision factor*/
		BIT_L(MY_SYSCTRL->RCC,17);
		BIT_L(MY_SYSCTRL->RCC,18);
		BIT_H(MY_SYSCTRL->RCC,19);
	#elif PWM_DIV == 64
		/*enable pwm devision*/
		BIT_H(MY_SYSCTRL->RCC,20);
		/*Assign devision factor*/
		BIT_H(MY_SYSCTRL->RCC,17);
		BIT_H(MY_SYSCTRL->RCC,18);
		BIT_H(MY_SYSCTRL->RCC,19);
	#endif
	
}
void SysCtrl_EnPeripheralClk  (SysCtrl_PeripheralID_Type PeripheralIndex)
{
	MY_SYSCTRL->R_ClkCtrl[PeripheralIndex]=0xFF;
}
void SysCtrl_DisPeripheralClk (SysCtrl_PeripheralID_Type PeripheralIndex)
{
	MY_SYSCTRL->R_ClkCtrl[PeripheralIndex]=0x00;
}
void SysCtrl_ResetPeripheral  (SysCtrl_PeripheralID_Type PeripheralIndex)
{
	/*Held Peripheral in reset */
	MY_SYSCTRL->SwR[PeripheralIndex]=0xFF;
	/*Release Peripheral*/
	MY_SYSCTRL->SwR[PeripheralIndex]=0xFF;
}
uint8 SysCtrl_GetPeripheralStatus  (SysCtrl_PeripheralID_Type PeripheralIndex, uint8 PeripheralNum)
{
	/*returns 1 if ready to access*/
	return GET_BIT(MY_SYSCTRL->PrRDY[PeripheralIndex],PeripheralNum);
}


SysCtrl_RST_CAUSE_Type SysCtrl_GetRstCause(void)
{
	SysCtrl_RST_CAUSE_Type temp;
	/*Store the status flags*/
	temp = MY_SYSCTRL->RESC & 0x3F;
	/*Clear these flags*/
	MY_SYSCTRL->RESC = MY_SYSCTRL->RESC & (uint32)(~0x1003F);
	return temp;
}
 void SysCtrl_PowerUpPLL(void) 
 {
	/*Powring up the PLL*/	
	BIT_L(MY_SYSCTRL->RCC,(uint32)13);
 }


/**********************************************************************************************************************
 *  END OF FILE: SysCtrl.c
 *********************************************************************************************************************/
