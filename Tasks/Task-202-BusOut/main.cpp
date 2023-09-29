#include "mbed.h"

// Hardware Definitions
//top of traf LEDS
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

//these are the board LEDs
#define greenMSB PB_0
#define blueMSB PB_7
#define redMSB PB_14

// Objects
// DigitalOut grn(TRAF_GRN1_PIN);
// DigitalOut yel(TRAF_YEL1_PIN);
// DigitalOut red(TRAF_RED1_PIN,1);

//does this work the same as the BSRR or is it not atomic?


BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
BusOut ledsB(greenMSB, blueMSB, redMSB);
//BusOut ledsTwo(TRAF_RED2_PIN, TRAF_YEL2_PIN, TRAF_GRN2_PIN);

int main()
{
    while (true) {

        ledsB = 7;
        wait_us(500000);

        leds = 0;   //Binary 000
        wait_us(500000);
        leds = 1;   //Binary 111
        wait_us(500000);    
        leds = 2;   //Binary 111
        wait_us(500000);  
        leds = 3;   //Binary 111
        wait_us(500000);  
        leds = 4;   //Binary 111
        wait_us(500000);  
        leds = 5;   //Binary 111
        wait_us(500000);  
        leds = 6;   //Binary 111
        wait_us(500000);  
        leds = 7;   //Binary 111
        wait_us(500000);  
        ledsB = 0;
        wait_us(500000);
    }
}


