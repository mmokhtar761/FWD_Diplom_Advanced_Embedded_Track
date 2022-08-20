/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/*                                        **VI, Please read**
Note: If the ADC module is not using the PIOSC as the clock source, the system clock must be
	  at least 16 MHz. 
    : When the USB module is in operation, MOSC must be the clock source, either with or without using the PLL,
 	  and the system clock must be at least 20 MHz.
*/
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CINFIG MACROS
 *********************************************************************************************************************/
 /*Please before starting this doc, open datasheet page 222 to know more about parametars */
/*
Clock source selection. Please, choose one of the following.
	MOSCDIS        (Main OSC external)
	PIOSC          (Precision Internal OSC(16 MHz))
	PIOSC_DIV_4    (Precision Internal OSC(16/4 MHz))
	LFIOSC         (Internal OSC (30 kHz), intended to be used in sleep mode)
*/
#define PRIM_CLK_SOURCE PIOSC

#if PRIM_CLK_SOURCE != LFIOSC || PRIM_CLK_SOURCE != PIOSC_DIV_4
	/*ENABLE or DISABLE PLL (400MHZ)*/
	#define EN_PLL DISABLE
		#if EN_PLL == ENABLE
		/*ENABLE or DISABLE PLL (400MHZ) division by 2 */
		#define PLL_DIV_BY_2  ENABLE
		#endif
#endif
 /*use 1, 2, 3, 4, .....16*/
 /*Note: When using the PLL, 
		->the VCO frequency of 400 MHz is predivided by 2 before the
		divisor is applied.
		->division must be 3 or more
*/
#define SYS_DIV 1
#if PRIM_CLK_SOURCE == PIOSC || PRIM_CLK_SOURCE == PIOSC_DIV_4
/*if so, please mention the attached crystal freq by the code below*/
/*Suitable values for USB is mentioned by -> (USB)*/
/*
0x06 4 MHz 
0x07 4.096 MHz 
0x08 4.9152 MHz 
0x09 5 MHz (USB)
0x0A 5.12 MHz
0x0B 6 MHz (USB)
0x0C 6.144 MHz
0x0D 7.3728 MHz
0x0E 8 MHz (USB)
0x0F 8.192 MHz
0x10 10.0 MHz (USB)
0x11 12.0 MHz (USB)
0x12 12.288 MHz
0x13 13.56 MHz
0x14 14.31818 MHz
0x15 16.0 MHz (USB)
0x16 16.384 MHz
0x17 18.0 MHz (USB)
0x18 20.0 MHz (USB)
0x19 24.0 MHz (USB)
0x1A 25.0 MHz (USB)
*/
#define PIOSC_OSC_FRQ_CODE 0x15
#endif
/*PWM used system clock devided by a factor*/
/*Use 1 to disable devision or values 2,,4,,8,,16,,32,,64 to be devided by */
#define PWM_DIV  16

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
