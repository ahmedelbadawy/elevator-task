#include "Main.h"
#include "Port.h"
#include "buttons.h"


void Button_Init(tBUTTON BUTTON)
{
    /* Add your code here! */
    /* Configure led pins as output */
    switch (BUTTON)
    {
        case BUTTON_OPEN:
            GPIO_InitPortPin(OPEN_PORT_CR, OPEN_PIN, GPIO_IN);
            break;
        default:
            /* Should not come here */
            break;
    }