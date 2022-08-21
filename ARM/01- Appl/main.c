
#include "IntCtrl.h"
#include "SysCtrl.h"
#include "GPIO.h"
#include "SysTick.h"

GPIO_PinCfg_type  PinCfg;
void testsystick(void)
{
	volatile static uint8 x;
	x++;
	GPIO_PinTog  (PORTE_ID, P1);

}

int main (void)
	{
		PinCfg.PinPort = PORTE_ID ;
		PinCfg.PinIndex = P1;
		PinCfg.PinDir = GPIO_PinDirO;
		PinCfg.PinMode = DIOFnc_Pin;
		PinCfg.PinStrnth = DR8R;
		PinCfg.PinPuPd = PULL_DOWN;
	
		SysCtrl_VoidInit();
		SysCtrl_EnPeripheralClk  ((SysCtrl_PeripheralID_Type) SysCtrl_GPIO);
		GPIO_CfgPins (&PinCfg, 1);
		SysTickStartMultiShot ( 0xB71AFF);
    //SysTickStartOneShot   (SysTickCount_type CopyRldVal);
    //SysTickStop           (void);
    //SysTick_CountGetElpsd  (void);
    //SysTick_CountGetRemn   (void);
    SysTickEnNotf         (testsystick);
		//SysTickDisNotf        (void);
		
		
		
		while (1)
		{
		//GPIO_PinMan  ( PORTE_ID, P1,GPIO_PinH);
		//GPIO_PinMan  ( PORTE_ID, P1,GPIO_PinL);
		//IntCrtl_voidinitIntCrtl ();
		//while (1);
		//return 0;
		}
	}

//0x40000000, 0x5FFFFFFF
	
	