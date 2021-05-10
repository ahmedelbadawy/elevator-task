#include "Main.h"
#include "Port.h"
#include "Led.h"
#include "buttons.h"

void Buzeer(void) interrupt 1
{
   
  LED_Toggle(LED_1);
  IE1=0;
}


void main()
{
    
    // diable the watch dog
    WDTCN = 0x0DE;
    WDTCN = 0x0AD;

    OSCICN = 0x014; // 2MH clock

    // config cross bar
    XBR0 = 0x00;
    XBR1 = 0x016; // enable interrupt crossbar
    XBR2 = 0x40; // Cross bar enabled , weak Pull-up enabled

    EA = 1; //enable global interrupt
    // EX0 = 1 ; // enable external interrupt 0
    EX1 = 1 ; // enable external interrupt 1

    CKCON |= 0x0c ; //Select the system clock
    TMOD &= ~0x7F; //disable gate1
    TMOD |= 0x04; //enable T0 counter

    ET0 = 1; //enable interrupt of timer0
    ET1 = 1; //enable interrupt of timer1

    TL0 = 0xfc;
    TH0 = 0xff;

    TL1 = 0xfb;
    TH1 = 0xff;
    LED_Init(LED_1,LED_OFF);
    LED_Init(LED_2,LED_OFF);
    BUTTON_Init(BUTTON_OPEN);
	// while (1){
    //     LED_SetState(tLED led, tLED_State state);
	// }


}