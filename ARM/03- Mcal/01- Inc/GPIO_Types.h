/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "GPIO_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
PORTA_ID,
PORTB_ID,
PORTC_ID,
PORTD_ID,
PORTE_ID,
PORTF_ID
}GPIO_PortID_type;
typedef enum
{
P1,
P2,
P3,
P4,
P5,
P6,
P7
}GPIO_PinIndex_type;
typedef enum
{
	GPIO_PinDirI,
	GPIO_PinDirO
}GPIO_PinDir_type;

typedef enum
{
	DIOFnc_Pin,
	ALTRFnc1_Pin,
	ALTRFnc2_Pin,
	ALTRFnc3_Pin,
	ALTRFnc4_Pin,
	ALTRFnc5_Pin,
	ALTRFnc6_Pin,
	ALTRFnc7_Pin,
	ALTRFnc8_Pin,
	ALTRFnc9_Pin,
	ALTRFnc14_Pin = 14,
	ALTRFnc15_Pin,
	AnlgFn_Pin,
	uDMAFnc_Pin
}GPIO_PinMode_type;

typedef enum
{
	DR2R,         //GPIO 2-mA Drive Select
	DR4R,         //GPIO 4-mA Drive Select
	DR8R          //GPIO 8-mA Drive Select

} GPIO_Drve_Strnth;
typedef enum
{
	OPEN_DRAIN,
	PULL_UP,
	PULL_DOWN
} GPIO_PadPuPd_type;
typedef struct
{
	GPIO_PortID_type    PinPort;
	GPIO_PinIndex_type  PinIndex;
	GPIO_PinDir_type    PinDir;
	GPIO_PinMode_type   PinMode;
	GPIO_Drve_Strnth    PinStrnth;
	GPIO_PadPuPd_type   PinPuPd;
} GPIO_PinCfg_type;


typedef enum
{
	GPIO_PinL,
	GPIO_PinH
}GPIO_PinLvl_type;
typedef enum
{
	GPIO_NibleL,
	GPIO_NibleH
}GPIO_NibleHL_type;

#endif  /* GPIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO_Types.h
 *********************************************************************************************************************/
