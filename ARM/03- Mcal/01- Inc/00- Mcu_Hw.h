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
	volatile uint32 STCTRL;      //SysTick Control and Status Register
	volatile uint32 STRELOAD;    //SysTick Reload Value Register
	volatile uint32 STCURRENT;   //SysTick Current Value Register
} SYS_TICK_RegType;
typedef struct
{
  volatile uint32 ENR[5];        //IRQ set-enable registers ID 0-138
  uint32   RESERVED0[26];
  volatile uint32 DISR[5];        //IRQ clear-enable registers ID 0-63
  uint32   RESERVED1[26];
  volatile uint32 PEND[5];        //IRQ set-pending registers ID 0-63
  uint32   RESERVED2[26];
  volatile uint32 UNPEND[5];      //IRQ clear-pending registers ID 0-63
  uint32   RESERVED3[26];
  volatile uint32 ACTIVER[5];     //IRQ active bit registers ID 0-63
  uint32   RESERVED4[61];
  volatile uint32 PRI[35];        //IRQ priority registers
  volatile uint32 SWTRIG;         //Software Trigger Interrupt
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

typedef struct
{
  volatile uint32 DID0;            //Device Identification 0
  volatile uint32 DID1;            //Device Identification 1
  uint32   RESERVED1[10];       
  volatile uint32 PBORCTL;         //Brown-Out Reset Control
  uint32   RESERVED2[7];
  volatile uint32 RIS;             //Raw Interrupt Status
  volatile uint32 IMC;             //Interrupt Mask Control
  volatile uint32 MISC;            //Masked Interrupt Status and Clear
  volatile uint32 RESC;            //Reset Cause
  volatile uint32 RCC;             //Run-Mode Clock Configuration
  uint32   RESERVED3[2];
  volatile uint32 GPIOHBCTL;       //GPIO High-Performance Bus Control
  volatile uint32 RCC2;            //Run-Mode Clock Configuration 2
  uint32   RESERVED4[2];
  volatile uint32 MOSCCTL;         //Main Oscillator Control
  uint32   RESERVED5[49];
  volatile uint32 DSLPCLKCFG;      //Deep Sleep Clock Configuration
  uint32   RESERVED6[1];
  volatile uint32 SYSPROP;         //System Properties 
  volatile uint32 PIOSCCAL;        //Precision Internal Oscillator Calibration
  volatile uint32 PIOSCSTAT;       //Precision Internal Oscillator Statistics
  uint32   RESERVED7[2];
  volatile uint32 PLLFREQ0;        //PLL Frequency 0
  volatile uint32 PLLFREQ1;        //PLL Frequency 1
  volatile uint32 PLLSTAT;         //PLL Status
  uint32   RESERVED8[7];
  volatile uint32 SLPPWRCFG;       //Sleep Power Configuration
  volatile uint32 DSLPPWRCFG;      //Deep-Sleep Power Configuration
  uint32   RESERVED9[9];
  volatile uint32 LDOSPCTL;        //LDO Sleep Power Control
  volatile uint32 LDOSPCAL;        //LDO Sleep Power Calibration
  volatile uint32 LDODPCTL;        //LDO Deep-Sleep Power Control
  volatile uint32 LDODPCAL;        //LDO Deep-Sleep Power Calibration
  uint32   RESERVED10[2];
  volatile uint32 SDPMST;          //Sleep / Deep-Sleep Power Mode Status
  uint32   RESERVED11[76];
  volatile uint32 PrP[24];         //Peripheral Present IDs {4,9,11,12,18,19,20,21} ARE RESERVED  (RO) 
  uint32   RESERVED12[104];
  volatile uint32 SwR[24];          //Software Reset  IDs {4,9,11,12,18,19,20,21} ARE RESERVED
  uint32   RESERVED13[40];
  volatile uint32 R_ClkCtrl[24];    //Run Mode Clock Gating Control IDs {4,9,11,12,18,19,20,21} ARE RESERVED
  uint32   RESERVED14[40];
  volatile uint32 S_ClkCtrl[16];   //Sleep Mode Clock Gating Control
  uint32   RESERVED15[40];
  volatile uint32 DS_ClkCtrl[16];   //Deep-Sleep Mode Clock Gating Control
  uint32   RESERVED16[104];
  volatile uint32 PrRDY[16];        //Peripheral Ready (RO)
} SysCtrl_RegType;
  
  typedef struct
{
	volatile uint32 GPIODATA;
	volatile uint32 GPIODATA_MSK[255];
	volatile uint32 GPIODIR;
	volatile uint32 GPIOIS;             
	volatile uint32 GPIOIBE;
	volatile uint32 GPIOIEV;
	volatile uint32 GPIOIM;
	volatile uint32 GPIORIS;
	volatile uint32 GPIOMIS;
	volatile uint32 GPIOICR;
	uint32   RESERVED2[55];
    volatile uint32 GPIOAFSEL;
    volatile uint32 GPIODR[3];
    volatile uint32 GPIOODR;
    volatile uint32 GPIOPUR;
    volatile uint32 GPIOPDR;
    volatile uint32 GPIOSLR;
    volatile uint32 GPIODEN;
    volatile uint32 GPIOLOCK;
    volatile uint32 GPIOCR;
    volatile uint32 GPIOAMSEL;
    volatile uint32 GPIOPCTL;
    volatile uint32 GPIOADCCTL;
    volatile uint32 GPIODMACTL;
   	uint32   RESERVED3[678];
    volatile uint32 GPIOPeriphID4;
    volatile uint32 GPIOPeriphID5;
    volatile uint32 GPIOPeriphID6;
    volatile uint32 GPIOPeriphID7;
    volatile uint32 GPIOPeriphID0;
    volatile uint32 GPIOPeriphID1;
    volatile uint32 GPIOPeriphID2;
    volatile uint32 GPIOPeriphID3;
    volatile uint32 GPIOPCellID0;
    volatile uint32 GPIOPCellID1;
    volatile uint32 GPIOPCellID2;
    volatile uint32 GPIOPCellID3CA;
} GPIO_PORT_RegType;
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 /*** Cortex M-4 peripheral's registers BaseAdd ***/
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
/*** Vendor peripheral's registers BaseAdd ***/

#define SCB_BASE_ADDRESS              ((volatile uint32)0x400FE000)
#define GPIO_PA_APB_BASE_ADDRESS      ((volatile uint32)0x40004000)
#define GPIO_PB_APB_BASE_ADDRESS      ((volatile uint32)0x40005000)
#define GPIO_PC_APB_BASE_ADDRESS      ((volatile uint32)0x40006000)
#define GPIO_PD_APB_BASE_ADDRESS      ((volatile uint32)0x40007000)
#define GPIO_PE_APB_BASE_ADDRESS      ((volatile uint32)0x40024000)
#define GPIO_PF_APB_BASE_ADDRESS      ((volatile uint32)0x40025000)

#define MY_SYSCTRL                    ((SysCtrl_RegType *)SCB_BASE_ADDRESS)
#define MY_PA                         ((GPIO_PORT_RegType *)GPIO_PA_APB_BASE_ADDRESS)
#define MY_PB                         ((GPIO_PORT_RegType *)GPIO_PB_APB_BASE_ADDRESS)
#define MY_PC                         ((GPIO_PORT_RegType *)GPIO_PC_APB_BASE_ADDRESS)
#define MY_PD                         ((GPIO_PORT_RegType *)GPIO_PD_APB_BASE_ADDRESS)
#define MY_PE                         ((GPIO_PORT_RegType *)GPIO_PE_APB_BASE_ADDRESS)
#define MY_PF                         ((GPIO_PORT_RegType *)GPIO_PF_APB_BASE_ADDRESS)


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define SCB_ABINT_W_KEY 0x05FA

#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
