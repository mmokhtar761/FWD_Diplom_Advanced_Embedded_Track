
#include "IntCtrl.h"
#include "SysCtrl.h"
#include "GPIO.h"
#include "SysTick.h"
#include "LedDr.h"

static uint8 x;
int main (void)
	{
		SysCtrl_VoidInit();
		SysCtrl_EnPeripheralClk  ((SysCtrl_PeripheralID_Type) SysCtrl_GPIO);
		LedDr_LedInit();
		LedFlasherAsyn (0,4,2);
		while (1){
			x++;
			if (x==0xF) x=0;

		}
		
	}

//0x40000000, 0x5FFFFFFF
	
