/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LedDr.c
 *        \brief  
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPIO.h"
#include "SysTick.h"
#include "LedDr.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
/*Array of pin configuration of the same number of leds*/
static GPIO_PinCfg_type PinCfg [LED_ATTCH_NUM];
static uint8 localCounter;
static uint8 localOnTime;
static uint8 localOffTime;
static LedIndex_type localLedIndex;
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
void LedDr_LedInit(void)
{
	#if  LED_ATTCH_NUM == 1
	/*create one pin config var*/
	(*PinCfg).PinPort   = LED0_PORT ;
	(*PinCfg).PinIndex  = LED0_PIN;
	(*PinCfg).PinDir    = GPIO_PinDirO;
	(*PinCfg).PinMode   = DIOFnc_Pin;
	(*PinCfg).PinStrnth = DR8R;
	(*PinCfg).PinPuPd   = PULL_DOWN;
	#elif LED_ATTCH_NUM > 1
	uint8 i;
	INIT_LED_ARR;
	for (i=0;i<LED_ATTCH_NUM;i++)
	{
		PinCfg[i].PinDir    = GPIO_PinDirO;
		PinCfg[i].PinMode   = DIOFnc_Pin;
		PinCfg[i].PinStrnth = DR8R;
		PinCfg[i].PinPuPd   = PULL_DOWN;
	}
	#else error "Calling led init with no configured leds"
	#endif
	/*pass the config parameters to gpio driver*/
	GPIO_CfgPins (PinCfg, LED_ATTCH_NUM);
}
void LedDrHigh (LedIndex_type LedIndex)
{
	GPIO_PinMan  (PinCfg[LedIndex].PinPort,PinCfg[LedIndex].PinIndex,GPIO_PinH);
}
void LedDrLow  (LedIndex_type LedIndex)
{
	GPIO_PinMan  (PinCfg[LedIndex].PinPort,PinCfg[LedIndex].PinIndex,GPIO_PinL);
}
void LedTog (LedIndex_type LedIndex)
{
	GPIO_PinTog  (PinCfg[LedIndex].PinPort,PinCfg[LedIndex].PinIndex);
}
void LedFlasherAsyn (LedIndex_type LedIndex,uint8 OnTmSec,uint8 OffTmSec)
{
	localCounter = 0;
	localOnTime  = OnTmSec;
	localOffTime = OffTmSec;
	localLedIndex = LedIndex;
	LedDrHigh ((LedIndex_type) 0 );
	//SysTickStartMultiShot ( 0xB71AFF);
	SysTickStartMultiShot ( 0xFF1AFF);
	SysTickEnNotf         (sysTickNotfHandler);
}
void LedStopFlasherAsyn (LedIndex_type LedIndex)
{
	  SysTickStop ();
	  SysTickDisNotf ();
   	LedDrLow (LedIndex);
    localOnTime = 0;
    localOffTime = 0;
}

void sysTickNotfHandler (void)
{
	localCounter++;
	if (localCounter == localOnTime) 
	{
		LedDrLow (localLedIndex);
		return;
	}
	if (localCounter>localOnTime)
	{
		if ((localCounter-localOnTime) == localOffTime)
		{
			LedDrHigh ((LedIndex_type) 0 );
			localCounter = 0;
		}
	}
}
/**********************************************************************************************************************
 *  END OF FILE: LedDr.c
 *********************************************************************************************************************/
