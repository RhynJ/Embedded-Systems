#include "mbed.h"

//this can only control pins on ther same port
//this can help with timing skew 

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

//these are the board LEDs
#define TRAF_GRN2_PIN PB_0
#define TRAF_YEL2_PIN PB_7
#define TRAF_RED2_PIN PB_14


//this tell the register which bits we want to activate 
#define LEDMASK 0b0000000001001100
#define portBMask 0b0100000010000001

// Objects
PortOut leds(PortC, LEDMASK);
PortOut leds2(PortB, portBMask);

int main()
{
    while (true) {
        leds = 0;   //Binary 000
        leds2 = 0;
        wait_us(500000);
        leds = 0xFF;   //Binary 11111111
        leds2 = 0xFF;  //binary 11111111_1111111
        wait_us(500000);    
    }
}




