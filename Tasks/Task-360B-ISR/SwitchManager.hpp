#ifndef __SWITCH_MANAGER__
#define __SWITCH_MANAGER__
#include "uop_msb.h"

#include <chrono>
#include <ratio>
using namespace uop_msb;
using namespace chrono;

#include "mbed.h"
// This class manages an Interrupt in and LED output
// It automatically manages the switch-debounce using edge detection and timers
class SwitchManager {
private:
  InterruptIn switchInterrupt;
  DigitalOut led;
  Timeout t;
  static volatile uint32_t count;

  void waitForRising();
  void waitForStabilityRising();
  void waitForFalling();
  void waitForStabilityFalling();

public:
  SwitchManager(PinName intInPin, PinName gpioPin)
      : switchInterrupt(intInPin), led(gpioPin) {
    count = 0;
    // Listen for rising edge
    //this is almost like a definition as to what to look out for
    switchInterrupt.rise(callback(this, &SwitchManager::waitForRising));
  }
  ~SwitchManager() {
    // Turn off LED and shut off any ISRs
    led = 0;
    switchInterrupt.rise(NULL);
    switchInterrupt.fall(NULL);
    t.detach();
  }

  //This is a STATIC member of the CLASS
  
  static uint32_t getCount(){
    //this ensures that nothing can interrupt this while it is running
    CriticalSectionLock lock;
    return count; 
  }
};

class Flashy {
    private:
    //Composition in action here
    DigitalOut led;
    Ticker tick;
    //Internal state
    microseconds _interval;
    PinName _pin;
    bool _enabled = false;

    void timerISR()  {
        led = !led;
    }

    void enable(bool en)
    {
        if (en == _enabled) return;

        if (en) {
            tick.attach(callback(this, &Flashy::timerISR), _interval);
        } else {
            tick.detach();
            led = 0;
        }
        _enabled = en;
    }

    public:
    Flashy(PinName pin, microseconds t) : led(pin,0), _pin(pin), _interval(t) {
        enable(false);
    }
    //OVERLOAD constructor
    Flashy(PinName pin) : Flashy(pin, 500ms) {
    }
    ~Flashy() {
        enable(false);
        led = 0;
    }

    //OVERLOAD private enable
    void enable() {
        enable(true);
    }

    void disable() {
        enable(false);
    }

    //Setter and getter for _inteval
    void setInterval(microseconds t) {
        _interval = t;
        if (_enabled) {
            //Reenable to force update
            disable();
            enable();
        }
    }
    microseconds getInterval() {
        return _interval;
    }
};

#endif