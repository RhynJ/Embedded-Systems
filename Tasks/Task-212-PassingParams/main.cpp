#include "mbed.h"
#include "complexSum.hpp"
#include "complexConjugate.hpp"
#include "complexNegate.hpp"





// TASK - write and test complexConjugate, complexNegate, complexSubtract, complexMagnitude, complexMultiply and complexDivide

int main() {
    printf("\n\nTASK212\n");

    //Create instance of a complex number
    ComplexNumber_C p = {2.0, 3.0};
    ComplexNumber_C q = {1.0, 1.0};
    complexDisplay("p", p);
    complexDisplay("q", q);
 

    //tells us what finction we want to use and the variables we want to pass it
    ComplexNumber_C sum = complexAdd(p, q);
    //display the answer using the function 
    complexDisplay("p+q", sum);


    //Conjugate
    ComplexNumber_C conjY = complexConj(sum);
    complexConjDisplay("The conjugate fo this is", conjY);

    //negative
    //this uses pointers to modify the paramater directly 
    complexNeg(sum);
    complexNegDisplay("the negative of this is ",  sum);


    


}
