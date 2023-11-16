#pragma once
#include <cstdint>
#include <iostream>



/*
T is the data type of the data
R is the data type of the mean (and sum)
N is the buffer size
*/
template<class T, class R>
class runningMean {
private:
    uint32_t N;
    //means the buffer is expected to be of type T
    T *buffer;
    R sum;
    int index;

    // Computing a running sum (Optimised for speed - no checks for overflows!!!)
    void addAndUpdate(T nextSample) {
        // Sum is updated - add new sample, subtract oldest
        sum = sum + nextSample - buffer[index];
        buffer[index] = nextSample;     //Overwrite oldest sample
        index = (index + 1) % N;        //Update position of oldest sample
    }

public:
    //Constructor
    runningMean(uint32_t N_, T initValue = (T)0) : N(N_) {
        //Initialise data to known state
        sum = (T)0;
        index = 0;
        //requests a block of memory to store N of type T
        //new will return the start address of the block of memory and save it to the buffer. this will only happen if it is able to do so
        //this will be dedclared at run time 
        buffer = new T[N];  //Allocate memory on the heap
        for (unsigned int n=0; n<N; n++) buffer[n] = (T)0;
    }   
    ~runningMean() {
        //Give back the memory
        //This is critical unless you want a memory leak!
        //this will clear the memory for buffer so that it can be us    ed for something else
    
        delete [] buffer;
        // See https://docs.microsoft.com/en-us/cpp/cpp/delete-operator-cpp?view=msvc-170 for a disussion on delete []
    }

    //Used to add a sample to the buffer
    void operator += (T sample) {
        this->addAndUpdate(sample);
    }

    //Used to read the mean
    operator R() {
        return sum/(R)N;             //Return the mean, using the precision of type R
    }
};

