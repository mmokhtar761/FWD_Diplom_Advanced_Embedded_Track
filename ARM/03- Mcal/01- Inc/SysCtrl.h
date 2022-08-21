/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  IntCrtl
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef SysCtrl_H
#define SysCtrl_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "SysCtrl_Types.h"
#include "SysCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

	

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 /******************************************************************************
* \Syntax          : void SysCtrl_VoidInit(void)                                   
* \Description     : initialize System clock parsing the Configuration into SysCtrl registers 
*                    This function must be called at first (recom startup code)to init clock as configuered                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysCtrl_VoidInit(void);
/*
If ADC is intended to be used please call this funcion before init ADC
The ADC must be clocked from the PLL
*/
void SysCtrl_PowerUpPLL(void);
void SysCtrl_EnPeripheralClk  (SysCtrl_PeripheralID_Type PeripheralIndex);
void SysCtrl_DisPeripheralClk (SysCtrl_PeripheralID_Type PeripheralIndex);
void SysCtrl_ResetPeripheral(SysCtrl_PeripheralID_Type PeripheralIndex);
uint8 SysCtrl_GetPeripheralStatus  (SysCtrl_PeripheralID_Type PeripheralIndex, uint8 PeripheralNum);
SysCtrl_RST_CAUSE_Type SysCtrl_GetRstCause(void);

#endif  /* SysCtrl_H */

/**********************************************************************************************************************
 *  END OF FILE: SysCrtl.h
 *********************************************************************************************************************/
