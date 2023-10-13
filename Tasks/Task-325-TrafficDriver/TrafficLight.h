#ifndef __TRAFFICLIGHT__
#define __TRAFFICLIGHT__

#include "mbed.h"
using namespace chrono;
#include <stdio.h>
#include <iostream>
using namespace std;


//all io
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

#define TRAF_GRN2_PIN PC_9
#define TRAF_YEL2_PIN PC_8
#define TRAF_RED2_PIN PC_7

#define aBtn PG_0
#define bBtn PG_1
#define cBtn PG_2
#define dBtn PG_3



class TrafficLight 
{
    public:
    typedef enum {STOP, READY, GO, WARNING} LIGHT_STATE;

    
    //instance variables
    private:
    DigitalOut redLED;
    DigitalOut yellowLED;
    DigitalOut greenLED;

    


// DigitalInOut grnLED(TRAF_GRN2_PIN, PinDirection::PIN_OUTPUT, PinMode::OpenDrainNoPull, 0);

    DigitalInOut redLED2;//(TRAF_RED2_PIN, PinDirection::PIN_OUTPUT,PinMode::OpenDrainNoPull, 0);

    DigitalInOut yellowLED2;
    DigitalInOut greenLED2;

    
    Ticker t;
    LIGHT_STATE State;


    void yellowFlashISR();
    void flashYellow(bool flash);
    void updateOutput();
    double flashSpeed;


    public:
    //Constructor
    //these have internal access to the private functions
    TrafficLight(PinName redPin = TRAF_RED1_PIN, PinName yellowPin = TRAF_YEL1_PIN, PinName greenPin=TRAF_GRN1_PIN ,PinName redPin2 =TRAF_RED2_PIN, PinName yelloPin2 = TRAF_YEL2_PIN, PinName greenPin2=TRAF_GRN2_PIN); 

    //Destructor
    ~TrafficLight();

    //Advance the traffic lights to the next state
    LIGHT_STATE nextState();
    void stop();
    void getflashSpeed();
    
    //this can have data passed to it
    void setFlashSpeed(float u);




};


#endif