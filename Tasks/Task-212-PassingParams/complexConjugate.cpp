#include "mbed.h"
#include "complexConjugate.hpp"



ComplexNumber_C complexConj(ComplexNumber_C a) {
    ComplexNumber_C p = {a.real, -a.imag};
    return p;
}


void complexConjDisplay(const char *strName, const ComplexNumber_C p) {
    printf("%s = %f %f j\n", strName, p.real, p.imag);
}