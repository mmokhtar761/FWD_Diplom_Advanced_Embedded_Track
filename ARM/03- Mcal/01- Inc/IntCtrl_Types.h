/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define INTERRUPT_VECTOR_ADD_OFFSET ((volatile uint32*)0x00000040)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define GET_IRQ_VECTOR_ADD(IRQ_ID) (INTERRUPT_VECTOR_ADD_OFFSET + (volatile uint32*)(4 * IRQ_ID))
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
GPIOA_IRQ_ID,             //   0: GPIO Port A
GPIOB_IRQ_ID,             //   1: GPIO Port B
GPIOC_IRQ_ID,             //   2: GPIO Port C
GPIOD_IRQ_ID,             //   3: GPIO Port D
GPIOE_IRQ_ID,             //   4: GPIO Port E
UART0_IRQ_ID,             //   5: UART0 Rx and Tx
UART1_IRQ_ID,             //   6: UART1 Rx and Tx
SSI0_IRQ_ID,              //   7: SSI0 Rx and Tx
I2C0_IRQ_ID,              //   8: I2C0 Master and Slave
PMW0_FAULT_IRQ_ID,        //   9: PWM Fault
PWM0_0_IRQ_ID,            //  10: PWM Generator 0
PWM0_1_IRQ_ID,            //  11: PWM Generator 1
PWM0_2_IRQ_ID,            //  12: PWM Generator 2
QEI0_IRQ_ID,              //  13: Quadrature Encoder 0
ADC0SS0_IRQ_ID,           //  14: ADC Sequence 0
ADC0SS1_IRQ_ID,           //  15: ADC Sequence 1
ADC0SS2_IRQ_ID,           //  16: ADC Sequence 2
ADC0SS3_IRQ_ID,           //  17: ADC Sequence 3
WDT0_IRQ_ID,              //  18: Watchdog timer 0&1
TIMER0A_IRQ_ID,           //  19: Timer 0 subtimer A
TIMER0B_IRQ_ID,           //  20: Timer 0 subtimer B
TIMER1A_IRQ_ID,           //  21: Timer 1 subtimer A
TIMER1B_IRQ_ID,           //  22: Timer 1 subtimer B
TIMER2A_IRQ_ID,           //  23: Timer 2 subtimer A
TIMER2B_IRQ_ID,           //  24: Timer 2 subtimer B
COMP0_IRQ_ID,             //  25: Analog Comparator 0
COMP1_IRQ_ID,             //  26: Analog Comparator 1
/*27 reseved*/
SYSCTL_IRQ_ID = 28,       //  28: System Control (PLL OSC BO)
FLASH_IRQ_ID,             //  29: FLASH Memory Control and EEPROM Control
GPIOF_IRQ_ID,             //  30: GPIO Port F
/*31 & 32 reserved*/
UART2_IRQ_ID = 33,        //  33: UART2 Rx and Tx
SSI1_IRQ_ID,              //  34: SSI1 Rx and Tx
TIMER3A_IRQ_ID,           //  35: Timer 3 subtimer A
TIMER3B_IRQ_ID,           //  36: Timer 3 subtimer B
I2C1_IRQ_ID,              //  37: I2C1 Master and Slave
QEI1_IRQ_ID,              //  38: Quadrature Encoder 1
CAN0_IRQ_ID,              //  39: CAN0
CAN1_IRQ_ID,              //  40: CAN1
/*41 & 42 reserved*/
HIB_IRQ_ID = 43,          //  43: Hibernate
USB0_IRQ_ID,              //  44: USB0
PWM0_3_IRQ_ID,            //  45: PWM Generator 3
UDMA_IRQ_ID,              //  46: uDMA Software Transfer
UDMAERR_IRQ_ID,           //  47: uDMA Error
ADC1SS0_IRQ_ID,           //  48: ADC1 Sequence 0
ADC1SS1_IRQ_ID,           //  49: ADC1 Sequence 1
ADC1SS2_IRQ_ID,           //  50: ADC1 Sequence 2
ADC1SS3_IRQ_ID,           //  51: ADC1 Sequence 3
/*52 & 56 reserved*/
SSI2_IRQ_ID = 57,         //  57: SSI2 Rx and Tx
SSI3_IRQ_ID,              //  58: SSI3 Rx and Tx
UART3_IRQ_ID,             //  59: UART3 Rx and Tx
UART4_IRQ_ID,             //  60: UART4 Rx and Tx
UART5_IRQ_ID,             //  61: UART5 Rx and Tx
UART6_IRQ_ID,             //  62: UART6 Rx and Tx
UART7_IRQ_ID,             //  63: UART7 Rx and Tx
/*64 & 67 reserved*/
I2C2_IRQ_ID = 68,         //  68: I2C2 Master and Slave
I2C3_IRQ_ID,              //  69: I2C3 Master and Slave
TIMER4A_IRQ_ID,           //  70: Timer 4 subtimer A
TIMER4B_IRQ_ID,           //  71: Timer 4 subtimer B
/*72 & 91 reserved*/
TIMER5A_IRQ_ID = 92,      //  92: Timer 5 subtimer A
TIMER5B_IRQ_ID,           //  93: Timer 5 subtimer B
WTIMER0A_IRQ_ID,          //  94: Wide Timer 0 subtimer A
WTIMER0B_IRQ_ID,          //  95: Wide Timer 0 subtimer B
WTIMER1A_IRQ_ID,          //  96: Wide Timer 1 subtimer A
WTIMER1B_IRQ_ID,          //  97: Wide Timer 1 subtimer B
WTIMER2A_IRQ_ID,          //  98: Wide Timer 2 subtimer A
WTIMER2B_IRQ_ID,          //  99: Wide Timer 2 subtimer B
WTIMER3A_IRQ_ID,          // 100: Wide Timer 3 subtimer A
WTIMER3B_IRQ_ID,          // 101: Wide Timer 3 subtimer B
WTIMER4A_IRQ_ID,          // 102: Wide Timer 4 subtimer A
WTIMER4B_IRQ_ID,          // 103: Wide Timer 4 subtimer B
WTIMER5A_IRQ_ID,          // 104: Wide Timer 5 subtimer A
WTIMER5B_IRQ_ID,          // 105: Wide Timer 5 subtimer B
FPU_IRQ_ID,               // 106: System Exception (imprecise)
/* 107-133 reserved*/
PMW1_0_IRQ_ID = 134,      // 134: PWM 1 Generator 0
PWM1_1_IRQ_ID,            // 135: PWM 1 Generator 1
PWM1_2_IRQ_ID,            // 136: PWM 1 Generator 2
PWM1_3_IRQ_ID,            // 137: PWM 1 Generator 3
PWM1_FAULT_IRQ_ID         // 138: PWM 1 Fault
}IntCtrl_InterruptID;

typedef struct
{
  IntCtrl_InterruptID IRQid;
  uint8 u8GroupPriority;
  uint8 u8supPriority;
} ExPriphIRQ_type;

 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
