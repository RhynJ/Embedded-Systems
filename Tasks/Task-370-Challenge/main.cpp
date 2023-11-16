#include "mbed.h"
#include "uop_msb.h"
#include <chrono>
#include <cstdint>
#include <cstdio>
#include "runningMean.hpp"
using namespace uop_msb;

#define LDR1 PC_0

//Used this to 
AnalogIn LDR(LDR1);



Thread t1, t2;
void task1();
void task2();

Ticker tick, average;

void countISR();
void printISR();


long runningSumLDR;
unsigned int increment;
Mutex potLock;




int main(void)
{

    //running average #
    runningMean<uint16_t, double>  buf4(1000);


    tick.attach(&countISR, 1ms);
    average.attach(&printISR, 1000ms);

    t1.start(task1);
    t2.start(task2);

    

//4. Every 1s, it should print out the average of the past 1000 samples to the terminal. 

    while (true) {
        ThisThread::sleep_for(1000ms);
    }
    
}   




void task1() 
{
    while(true) {
    ThisThread::flags_wait_any(2);
    //this will read the pot

    potLock.lock();
    uint16_t uLDR = LDR.read_u16();    //12-bit Integer 0..4095
    runningSumLDR += uLDR;
    increment++;
    potLock.unlock();
    ThisThread::flags_clear(2); //Switch bounce can send multiples
    }    
}


void task2(){
    while(true){
        ThisThread::flags_wait_any(3);
        //this will read the pot

        potLock.lock();
        unsigned int average = runningSumLDR/increment;
        printf("The running average is %u \n", average);
        potLock.unlock();

        ThisThread::flags_clear(3);
}
}




void countISR(){
    //this will flag for task 1 to start
    t1.flags_set(2); //osSignalSet(t2.get_id(), 1);    
}


void printISR(){
    //this will flag task 2 to trigger
    t2.flags_set(3);
}