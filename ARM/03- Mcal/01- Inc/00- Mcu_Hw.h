/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
  volatile uint32  ENR[5]; //IRQ set-enable registers ID 0-138
  uint32   RESERVED0[27];
  volatile uint32 DISR[5]; //IRQ clear-enable registers ID 0-63
  uint32   RESERVED1[27];
  volatile uint32 PEND[5]; //IRQ set-pending registers ID 0-63
  uint32   RESERVED2[27];
  volatile uint32 UNPEND[5]; //IRQ clear-pending registers ID 0-63
  uint32   RESERVED3[27];
  volatile uint32 ACTIVER[5]; //IRQ active bit registers ID 0-63
  uint32   RESERVED4[62];
  volatile uint32 PRI[35]; //IRQ priority registers
  volatile uint32 SWTRIG;  //Software Trigger Interrupt
} INTCTRL_RegType;

typedef struct
{
  volatile uint32 CPUID;          //CPU ID Base
  volatile uint32 INTCTRL;        //Interrupt Control and State
  volatile uint32 VTABLE;         //Vector Table Offset
  volatile uint32 APINT;          //Application Interrupt and Reset Control
  volatile uint32 SYSCTRL;        //System Control
  volatile uint32 CFGCTRL;        //Configuration and Control
  volatile uint32 SYSPRI[3];      //System Handler Priority 1 TO 3
  volatile uint32 SYSHNDCTRL;     //System Handler Control and Stat
  volatile uint32 FAULTSTAT;      //Configurable Fault Status
  volatile uint32 HFAULTSTAT;     //Hard Fault Status
  volatile uint32 MMADDR;         //Memory Management Fault Address
  volatile uint32 FAULTADDR;      //Bus Fault Address

} SCB_RegType;
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS    ((volatile uint32)0xE000E000)

#define SYS_TICK_ADDRESS_OFFSET       ((volatile uint32)0x00000010)
#define INTCTRL_ADDRESS_OFFSET        ((volatile uint32)0x00000100)
#define SCB_ADDRESS_OFFSET            ((volatile uint32)0x00000D00)

#define SYS_TICK_ADDRESS              (CORTEXM4_PERI_BASE_ADDRESS + SYS_TICK_ADDRESS_OFFSET)
#define INTCTRL_ADDRESS               (CORTEXM4_PERI_BASE_ADDRESS + INTCTRL_ADDRESS_OFFSET)
#define SCB_ADDRESS                   (CORTEXM4_PERI_BASE_ADDRESS + SCB_ADDRESS_OFFSET)

#define MY_SYS_TICK                   ((SYS_TICK_RegType*)SYS_TICK_ADDRESS)
#define MY_INTCTRL                    ((INTCTRL_RegType *)INTCTRL_ADDRESS)
#define MY_SCB                        ((SCB_RegType *)SCB_ADDRESS)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define SCB_ABINT_W_KEY 0x05FA
 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
