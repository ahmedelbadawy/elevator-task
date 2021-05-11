#include "Main.h"
#include "Port.h"
#include "Led.h"
#include "buttons.h"

void Delay_MS(unsigned int ms){
    unsigned int i;
    unsigned int j;
    for(i=0; i<ms; i++){
        for(j=0; j<120; j++){
        }
    }
}
void Timer_init()
{
    TMOD = 0x01;
    TL0 = 0x00;
    TH0 = 0x4c;
    TR0 = 1;

}

void Led(void) interrupt 1
	
{   
    LED_Toggle(LED_1);
    LED_Toggle(LED_2);
    Delay_MS(400);
    LED_Toggle(LED_1);
    LED_Toggle(LED_2);
    TR0 = 0;


}

void Buzeer(void) interrupt 0
{
   
   TR0 = 0;
   TR0 = 1;
   
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
    EX0 = 1; // enable external interrupt 0
    EX1 = 1 ;  //enable external interrupt 1
    IT0 = 1;
    IT1 = 1;

    CKCON |= 0x00 ; //Select the system clock
    

    ET0 = 1; //enable interrupt of timer0

    Timer_init();
    //ET1 = 1; //enable interrupt of timer1

    

    // TL1 = 0xfb;
    // TH1 = 0xff;
    LED_Init(LED_1,LED_OFF);
    LED_Init(LED_2,LED_ON);
    BUTTON_Init(BUTTON_OPEN);
	// while (1){
    //     LED_SetState(tLED led, tLED_State state);
	// }
while(1){}

}