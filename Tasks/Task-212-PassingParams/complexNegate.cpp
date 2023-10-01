#include "mbed.h"
#include "complexNegate.hpp"



void complexNeg(ComplexNumber_C& a)
{
    a.real = -a.real;
    a.imag = -a.imag;
}



void complexNegDisplay(const char *strName, const ComplexNumber_C u)
{
        printf("%s = %f %f j\n", strName, u.real, u.imag);

}

//this is a c pointer and doenst work in C++
// void complexNegateInplace(ComplexNumber_C* u) {
//     u->imag = -u->imag;
//     u->real = -u->real;
// }

// void otherNegDisp(const char *strName, const ComplexNumber_C u)
// {
//         printf("%s = %f %f j\n", strName, u.real, u.imag);

// }