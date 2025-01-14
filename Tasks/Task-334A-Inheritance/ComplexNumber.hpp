#ifndef __COMPLEX_NUMBER__
#define __COMPLEX_NUMBER__
#include "DoubleNumber.hpp"


    //the name of the child-class : the name of the parent class
class ComplexNumber : public DoubleNumber {
                        //inherate all functions from DoubleNumber
private:

protected:
    double _imag;

public:                                 //pass to the parent class
    ComplexNumber(double r, double i) : DoubleNumber(r) {
        _imag = i;
        cout << "This is the constructor of the sub-class" << endl;
    }
    
    ComplexNumber() : ComplexNumber(0.0, 0.0) { }

    // ComplexNumber& operator=(double u) {
    //     DoubleNumber::operator=(u);
    //     return *this;
    // }

    // ComplexNumber& operator=(ComplexNumber& u) {
    //     DoubleNumber::operator=(u);
    //     return *this;
    // }

};

#endif