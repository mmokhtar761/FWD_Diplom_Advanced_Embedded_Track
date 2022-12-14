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
#include "IntCtrl.h"

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
/*
  This function must be called before any setting for priority
*/
void IntCrtl_voidinitIntCrtl (void)
{
	 #if SUB_PRIORITY_BITS + GROUP_PRIORITY_BITS != 3
     #error "Priority is described by 3 bits ONLY"
     #endif
  /*
    It is noted that :
       PRIGROUP value = sub-priority bits + 0x4
  */
  MY_SCB->APINT= ((SUB_PRIORITY_BITS + 0x4 )|(SCB_ABINT_W_KEY<<8))<<8;
  #if EDIT_PRIORITY_RUN_TIME == DISABLE
  //This section is added only if periority assignment is a prebuild configuration
	PRIORITY_INIT_CODE;
  #endif

}
/*
   DISABLE : disables all external peripherals IRQs
   ENABLE  : restores all last en/disable configurations to external peripherals IRQs
*/
void IntCrtl_voidEnDisExternalPeripheralIRQ(uint8 Copy_u8ENorDIS)
{
	//This var should be init in startup code to prevent assigning garbage
	static uint32 local_u32lastEnMask[5];
	uint8 i;
	if      (Copy_u8ENorDIS == ENABLE ){
		//assign the mask saved last time
		for (i=0;i<5;i++) MY_INTCTRL->ENR[i] = local_u32lastEnMask[i];
	}else if (Copy_u8ENorDIS == DISABLE ){
		//save the current mask
		for (i=0;i<5;i++) local_u32lastEnMask[i] = MY_INTCTRL->ENR[i];
		//disable all interrupts
		for (i=0;i<5;i++) MY_INTCTRL->DISR[i] = 0xFFFFFFFF;
	}
}

#if EDIT_PRIORITY_RUN_TIME == ENABLE
//This section is added only if run-time periority assignment is needed
/*
  > This function reseives a pointer to a variable of type ExPriphIRQ_type contains
  the data about (required IRQ id, group priority, and sup-priority)

  > Sets the group priority and superiority for this IRQ id
*/
void IntCrtl_voidConfigIRQpriority (ExPriphIRQ_type * Ptr_ExPriphIRQ)
{
	ASSIGN_PRIORITY(Ptr_ExPriphIRQ->IRQid,Ptr_ExPriphIRQ->u8GroupPriority,Ptr_ExPriphIRQ->u8supPriority);
}
#endif
/*
  Enable specific IRQ
*/
void IntCrtl_voidEnExtIRQ  (IntCtrl_InterruptID Copy_IRQ_ID)
{
	
	MY_INTCTRL->ENR [Copy_IRQ_ID/32] = 1<< (Copy_IRQ_ID%32); 
}
/*
  Disable specific IRQ
*/
void IntCrtl_voidDisExtIRQ (IntCtrl_InterruptID Copy_IRQ_ID)

{
	MY_INTCTRL->DISR [Copy_IRQ_ID/32] = 1<< (Copy_IRQ_ID%32);
}
/*
  Sets the pending flag
*/
void IntCrtl_voidSetPending (IntCtrl_InterruptID Copy_IRQ_ID)
{
	MY_INTCTRL->PEND [Copy_IRQ_ID/32] = 1<< (Copy_IRQ_ID%32);
}
/*
  Clears the pending flag
*/
void IntCrtl_voidClrPending (IntCtrl_InterruptID Copy_IRQ_ID)
{
	MY_INTCTRL->UNPEND [Copy_IRQ_ID/32] = 1<< (Copy_IRQ_ID%32);
}
/*
  Returns TRUE   if Copy_IRQ_ID is pending
          FALSE  if Copy_IRQ_ID isn't pending
*/
uint32  IntCrtl_uint32GetPending (IntCtrl_InterruptID Copy_IRQ_ID)
{
	return MY_INTCTRL->PEND [Copy_IRQ_ID/32];
}
/*
  Returns TRUE   if Copy_IRQ_ID is Active
          FALSE  if Copy_IRQ_ID isn't Active
*/
uint32  IntCrtl_uint32GetActive (IntCtrl_InterruptID Copy_IRQ_ID)
{
	return MY_INTCTRL->ACTIVER [Copy_IRQ_ID/32];
}


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
//void IntCrtl_Init(void)
//{

	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
   // APINT = 0xFA05|0x00001234;
    
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  


	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */


	

//}



/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
