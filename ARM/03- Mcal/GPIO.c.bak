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
#include "GPIO.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define GET_PORT_REG(PinArrIndix,REG_NAME)  (PORTsPtrArr[PtrArrPins[PinArrIndix].PinPort]-> REG_NAME)
#define PORTS_COUNT 6
#define MC_PIN_COUNT 64

#define GPIO_BB_MAN(PORTID,PIN_INDEX,VAL)   *((volatile uint32*)(((uint32)PORTsPtrArr[PORTID] - (uint32)PERI_BIT_BAND_REGION_ST + 0x3FC ) * 32 + PIN_INDEX * 4 + (uint32)PERI_BIT_BAND_ALIAS_ST )) = VAL
#define GPIO_BB_TOG(PORTID,PIN_INDEX)       *((volatile uint32*)(((uint32)PORTsPtrArr[PORTID] - (uint32)PERI_BIT_BAND_REGION_ST + 0x3FC ) * 32 + PIN_INDEX * 4 + (uint32)PERI_BIT_BAND_ALIAS_ST )) ^= 1
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static GPIO_PORT_RegType* const PORTsPtrArr[PORTS_COUNT] = {MY_PA,MY_PB,MY_PC,MY_PD,MY_PE,MY_PF};
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void GPIO_CfgPins (GPIO_PinCfg_type * PtrArrPins, uint8 CopyNumPins)
{
	uint8 i;
	if (CopyNumPins > MC_PIN_COUNT) return; /*To be added : return error*/
	/*Iterate to config all passed pins*/
	for (i=0;i<CopyNumPins;i++)
	{
		/*Set the direction of the GPIO port pins by programming the GPIODIR register. */
		MAN_BIT(GET_PORT_REG(i,GPIODIR),PtrArrPins[i].PinIndex,PtrArrPins[i].PinDir);
		/*Polling for the pin mode*/
		switch (PtrArrPins[i].PinMode)
		{
			/*Case of digital IO*/
			case DIOFnc_Pin:
				BIT_H(GET_PORT_REG(i,GPIODEN),PtrArrPins[i].PinIndex);
				break;
			/*Case of Analog*/
			case AnlgFn_Pin:
				BIT_H(GET_PORT_REG(i,GPIOAMSEL),PtrArrPins[i].PinIndex);
				break;
			/*Case of uDMA*/
			case uDMAFnc_Pin:
				/*TO BE DONE*/
				break;
			/*Case of alternative function*/
			default:
				/*Enable alternative fuction*/
				BIT_H(GET_PORT_REG(i,GPIOAFSEL),PtrArrPins[i].PinIndex);
				/*Choose which alternative function to be used*/
				MAN_NIBBLE(GET_PORT_REG(i,GPIOPCTL),4*(PtrArrPins[i].PinIndex),(PtrArrPins[i].PinMode) & 0xF);
		}
		/*Set the drive strength for the pin*/
		BIT_H(GET_PORT_REG(i,GPIODR)[PtrArrPins[i].PinStrnth],PtrArrPins[i].PinIndex);
		/*Program each pad in the port to have either pull-up, pull-down, or open drain functionality*/
		switch (PtrArrPins[i].PinPuPd)
		{
			/*Case of Open drain*/
			case OPEN_DRAIN:
				BIT_H(GET_PORT_REG(i,GPIOODR),PtrArrPins[i].PinIndex);
				break;
			/*Case of PULL_UP*/
			case PULL_UP:
				BIT_H(GET_PORT_REG(i,GPIOPUR),PtrArrPins[i].PinIndex);
				break;
			/*Case of PULL_DOWN*/
			case PULL_DOWN:
				BIT_H(GET_PORT_REG(i,GPIOPDR),PtrArrPins[i].PinIndex);
				break;
			/*Case of alternative function*/
		}
	}
	
}





void GPIO_PinMan  (GPIO_PortID_type PortId, GPIO_PinIndex_type PinIndix,GPIO_PinLvl_type PinState)
{
	
	GPIO_BB_MAN(PortId,PinIndix,PinState);
}
void GPIO_PinTog  (GPIO_PortID_type PortId, GPIO_PinIndex_type PinIndix)
{
	GPIO_BB_TOG(PortId,PinIndix);
	
}
/*functions to be implemented,, KEIL sim cant mask GPIOs*/
/*
void GPIO_NibMan  (GPIO_PortID_type PortId, GPIO_NibleHL_type NibleSide, uint8 NibleVal)
{
}
void GPIO_PortMan (GPIO_PortID_type PortId, uint8 PortVal)
{
}
void GPIO_PortMask(GPIO_PortID_type PortId, uint8 ManMask, uint8 MaskVal)
{
}
*/
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void GPIO_InitPins(void)                                      
* \Description     : initialize GPIO Module by parsing the Configuration 
*                    into GPIO registers                                    
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
