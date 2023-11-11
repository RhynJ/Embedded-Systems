#include "mbed.h"
#include "SwitchManager.hpp"

#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define BTN1_PIN PG_0
#define BTN2_PIN PG_1
#define USER_LED1 PB_0  // this is the green user LED 




    
int main() {
    
    Flashy FlashUserGreen(USER_LED1, 500ms);
    FlashUserGreen.enable();

    Flashy FlashTRAFYellow(TRAF_YEL1_PIN, 500ms);
    FlashTRAFYellow.enable();



    //Interrupt controlled red led using BTN1
    SwitchManager sm1(BTN1_PIN, TRAF_RED1_PIN);

    //Interrupt controlled green led using BTN2    
    SwitchManager sm2(BTN2_PIN, TRAF_GRN1_PIN);    
    

    
    //Now loop forever
    while(1) { 
        sleep();
        //this is static so only belong to the class, cannot be changed outside the class
        printf("count=%u\n",SwitchManager::getCount());
    };
}
