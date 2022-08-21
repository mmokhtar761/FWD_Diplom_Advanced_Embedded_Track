
#include "IntCtrl.h"
#include "SysCtrl.h"
#include "GPIO.h"

int main (void)
	{
		GPIO_PinCfg_type  PinCfg;
		PinCfg.PinPort = PORTE_ID ;
		PinCfg.PinIndex = P1;
		PinCfg.PinDir = GPIO_PinDirO;
		PinCfg.PinMode = DIOFnc_Pin;
		PinCfg.PinStrnth = DR8R;
		PinCfg.PinPuPd = PULL_DOWN;
	
		SysCtrl_VoidInit();
		SysCtrl_EnPeripheralClk  ((SysCtrl_PeripheralID_Type) SysCtrl_GPIO);
		while (1)
		{
		GPIO_CfgPins (&PinCfg, 1);
		//GPIO_PinMan  ( PORTE_ID, P1,GPIO_PinH);
		//GPIO_PinMan  ( PORTE_ID, P1,GPIO_PinL);
		GPIO_PinTog  (PORTE_ID, P1);
		//IntCrtl_voidinitIntCrtl ();
		//while (1);
		//return 0;
		}
	}


	
	