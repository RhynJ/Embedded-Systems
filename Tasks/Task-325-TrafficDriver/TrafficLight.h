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

// #define TRAF_GRN2_PIN PC_9
// #define TRAF_YEL2_PIN PC_8
// #define TRAF_RED2_PIN PC_7

#define aBtn PG_0
#define bBtn PG_1
#define cBtn PG_2
#define dBtn PG_3



class TrafficLight 
{
    public:
    typedef enum {STOP, READY, GO, WARNING} LIGHT_STATE;

    enum TRAF2 {RED = PC_7, YELLOW = PC_8, GREEN = PC_7};
    

    private:
    DigitalOut redLED;
    DigitalOut yellowLED;
    DigitalOut greenLED;

    // //second set of LEDs
    // DigitalInOut redLED2(TRAF_RED2_PIN, PinDirection::PIN_OUTPUT, PinMode::OpenDrainNoPull, 0);
    // DigitalInOut YellowLED2(TRAF_YEL2_PIN, PinDirection::PIN_OUTPUT, PinMode::OpenDrainNoPull, 0);
    // DigitalInOut greenLED2(TRAF_GRN2_PIN, PinDirection::PIN_OUTPUT, PinMode::OpenDrainNoPull, 0);

    
    Ticker t;
    LIGHT_STATE State;
    TRAF2 trafState;


    void yellowFlashISR();
    void flashYellow(bool flash);
    void updateOutput();
    double flashSpeed;


    public:
    //Constructor
    TrafficLight(PinName redPin = TRAF_RED1_PIN, PinName yellowPin = TRAF_YEL1_PIN, PinName greenPin=TRAF_GRN1_PIN);
    //,PinName redPin2 =TRAF_RED2_PIN, PinName yelloPin2 = TRAF_YEL2_PIN, PinName greenPin2=TRAF_GRN2_PIN); 

    //Destructor
    ~TrafficLight();

    //Advance the traffic lights to the next state
    LIGHT_STATE nextState();
    void stop();
    void setFlashSpeed(float u);
    void getflashSpeed();
    



};


#endif