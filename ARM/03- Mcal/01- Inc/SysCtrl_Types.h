/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYSCTRL_TYPES_H
#define SYSCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define MOSCDIS        0x0
#define PIOSC          0x1
#define PIOSC_DIV_4    0x2
#define LFIOSC         0x3
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
SysCtrl_WD,            //   0: Watchdog Timer
SysCtrl_TIMER,         //   1: 16/32-Bit General-Purpose Timer Peripheral
SysCtrl_GPIO,          //   2: General-Purpose Input/Output Peripheral
SysCtrl_DMA,           //   3: Micro Direct Memory Access Peripheral
SysCtrl_HIB =5 ,       //   5: Hibernation Peripheral 
SysCtrl_UART,          //   6: Universal Asynchronous Receiver/Transmitter Peripheral
SysCtrl_SSI,           //   7: Synchronous Serial Interface Peripheral
SysCtrl_I2C,           //   8: Inter-Integrated Circuit Peripheral 
SysCtrl_USB=10,        //  10: Universal Serial Bus Peripheral 
SysCtrl_CAN=13,        //  13: Controller Area Network Peripheral
SysCtrl_ADC,           //  14: Analog-to-Digital Converter Peripheral 
SysCtrl_ACMP,          //  15: Analog Comparator Peripheral
SysCtrl_PWM,           //  16: Pulse Width Modulator Peripheral 
SysCtrl_QEI,           //  17: Quadrature Encoder Interface Peripheral 
SysCtrl_EEPROM = 22,   //  22: EEPROM Peripheral Ready
SysCtrl_WTIMER         //  23: 32/64-Bit Wide General-Purpose Timer Peripheral Ready
}SysCtrl_PeripheralID_Type;

typedef enum
{
ExtRst,                   //   0: External Reset
PORst = 2,                //   1: Power-On Reset
BORst = 4,                //   2: Brown-Out Reset
WDT0Rst = 8,              //   3: Watchdog Timer 0 Reset
SWRst = 16,               //   4: Software Reset 
WDT1Rst = 32              //   5: Watchdog Timer 1 Reset
}SysCtrl_RST_CAUSE_Type;

 
#endif  /* SYSCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl_Types.h
 *********************************************************************************************************************/
