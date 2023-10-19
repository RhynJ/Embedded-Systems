#include "TrafficLight.h"

//Contructor
                            //these need to alread exist (here they exist in the header file)
TrafficLight::TrafficLight(PinName redPin, PinName yellowPin, PinName greenPin,
                           PinName redpin2, PinName yellowPin2, PinName greenPin2) 
                          :redLED(redPin), yellowLED(yellowPin), greenLED(greenPin),
                          redLED2(TRAF_RED2_PIN, PinDirection::PIN_OUTPUT,PinMode::OpenDrainNoPull, 0), yellowLED2(TRAF_YEL2_PIN, PinDirection::PIN_OUTPUT,PinMode::OpenDrainNoPull, 0), greenLED2(TRAF_GRN2_PIN, PinDirection::PIN_OUTPUT,PinMode::OpenDrainNoPull, 0)
{
    // These objects are already initialised in the member initialisation list above
    //this is always run when the instance is created
    redLED = 1;
    yellowLED = 0;
    greenLED = 0;

    redLED2 = 1;
    yellowLED2 = 1;
    greenLED2 = 0;

    // Timer off
    flashYellow(false);
}

//Destructor
TrafficLight::~TrafficLight()
{
    redLED = 1;
    yellowLED = 0;
    greenLED = 0;

} 

// Interrupt Service Routine (ISR)
void TrafficLight::yellowFlashISR() {
    yellowLED = !yellowLED;
    yellowLED2 = !yellowLED2;
}

// Private member function to switch flasher on or off
void TrafficLight::flashYellow(bool flash) {
    t.detach(); //Turn off ticker
    if (flash) {
        //Turn on ticker ..... Hmmm, interrupts!
        t.attach(callback(this, &TrafficLight::yellowFlashISR), flashSpeed );
    }
}

void TrafficLight:: stop()
{
    //here are 1 of 2 solutions
    
    State = STOP;
    updateOutput();


}

void TrafficLight::setFlashSpeed(float u)
{
    flashSpeed = u /1.1;
}

void TrafficLight::getflashSpeed()
{
    cout << "The flash speed is " << flashSpeed << "\n" << endl;
}



// Moore Machine - update outputs
//   name of class::funciton name 
void TrafficLight::updateOutput()
{
    switch (State)
    {
        case STOP:
            flashYellow(false);
            redLED = 1;
            yellowLED = 0;
            greenLED = 0;
            
            redLED2 = 1;
            yellowLED2 = 1;
            greenLED2 = 0;
            break;
        case READY:
            flashYellow(false);
            redLED = 0;
            yellowLED = 1;
            greenLED = 1;

            redLED2 = 1;
            yellowLED2 = 0;
            greenLED2 = 1;

            break;
        case GO:
            flashYellow(false);
            redLED = 0;
            yellowLED = 0;
            greenLED = 1;

            redLED2 = 0;
            yellowLED2 = 1;
            greenLED2 = 1;

            break;
        case WARNING:
            redLED = 0;
            flashYellow(true);
            greenLED = 0;

            redLED2 = 1;
            greenLED2 = 1;



            break;                
    }       
}




// Moore machine - next state logic
TrafficLight::LIGHT_STATE TrafficLight::nextState()
{
    // Update State
    switch (State)
    {
        case STOP:
            State = READY;
            break;
        case READY:
            State = GO;
            break;
        case GO:
            State = WARNING;
            break;
        case WARNING:
            State = STOP;
            break;
    }

    //As it says
    updateOutput();

    //Return the current state (for information)
    return State; 
} 






