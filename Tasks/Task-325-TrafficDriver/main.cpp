#include "mbed.h"
#include "TrafficLight.h"


TrafficLight lights;
DigitalIn sw(USER_BUTTON);
DigitalIn sw1(aBtn);
DigitalIn sw2(bBtn);
DigitalIn sw3(cBtn);
DigitalIn sw4(dBtn);

TrafficLight::LIGHT_STATE s;


int main()
{
    while (true) {
       

        i++;

       lights.setFlashSpeed(i);
       
        //Wait for switch press
        while (sw==0 && sw1==0);

        if (sw1== 1)
        {
            lights.stop();
        }
        else 
        {
            //Update lights
            s = lights.nextState();
        }
        




        //Debounce switch
        wait_us(300000);

        //Wait for switch release
        while (sw==1 && sw1==1);
        
        //Switch debounce
        wait_us(300000);
        
    }
}

