/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  IntCrtl
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef IntCrtl_H
#define IntCrtl_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl_Types.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define GET_PRIOTITY_VAL(Group_Pri,SupPri) (uint32)((Group_Pri<<SUB_PRIORITY_BITS)|SupPri)
#define ASSIGN_PRIORITY(IRQ_ID,Group_Pri,SupPri)\
	MY_INTCTRL->PRI[IRQ_ID/4] = GET_PRIOTITY_VAL(Group_Pri,SupPri)<<((IRQ_ID%4)*8+5)
	

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
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize IntCrtl\SCB Module by parsing the Configuration 
*                    into IntCrtl\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
 /*
  This function must be called before any setting for priority
*/
void IntCrtl_voidinitIntCrtl (void);
/*
   DIS : disables all external peripherals IRQs
   EN  : restores all last en/disable configurations to external peripherals IRQs
*/
void IntCrtl_voidEnDisExternalPeripheralIRQ(uint8 Copy_uint8ENorDIS);

#if EDIT_PRIORITY_RUN_TIME == ENABLE
/*
  > This function reseives a pointer to a variable of type ExPriphIRQ_type contains
  the data about (required IRQ id, group priority, and sup-priority)

  > Sets the group priority and superiority for this IRQ id
*/
void IntCrtl_voidConfigIRQpriority (ExPriphIRQ_type * Ptr_ExPriphIRQ);
#endif

/*
  Enable specific IRQ
*/
void IntCrtl_voidEnExtIRQ  (IntCtrl_InterruptID Copy_IRQ_ID);
/*
  Disable specific IRQ
*/
void IntCrtl_voidDisExtIRQ (IntCtrl_InterruptID Copy_IRQ_ID);

/*
  Sets the pending flag
*/
void IntCrtl_voidSetPending (IntCtrl_InterruptID Copy_IRQ_ID);
/*
  Clears the pending flag
*/
void IntCrtl_voidClrPending (IntCtrl_InterruptID Copy_IRQ_ID);
/*
  Returns TRUE   if Copy_uint8IRQ_ID is pending
          FALSE  if Copy_uint8IRQ_ID isn't pending
*/
uint32  IntCrtl_uint32GetPending (IntCtrl_InterruptID Copy_IRQ_ID);
/*
  Returns TRUE   if Copy_uint8IRQ_ID is Active
          FALSE  if Copy_uint8IRQ_ID isn't Active
*/
uint32  IntCrtl_uint32GetActive (IntCtrl_InterruptID Copy_IRQ_ID);

#endif  /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/
