#include "mbed.h"
#include "ComplexNumber.hpp"
#include <cstdio>



// main() runs in its own thread in the OS
int main()
{
    printf("\033[2J");//clears the terminal


    ComplexNumber c1(2.0,3.0);
    ComplexNumber c2(1.0,-1.0);
    ComplexNumber c1_copy = c1;
    c1.add(c2);   //c1 = c1 + c2

    printf("c1 \n");
    c1.display();

    printf("c1 copy \n");
    c1_copy.display();
    
    printf("c3 \n");
    ComplexNumber c3 = c1.addedTo(c2);
    c3.display();
    c3.conjugate();
    c3.display();

    //Create new scope
    {
        printf("test \n");
        ComplexNumber test(1.0, 2.0);
        test.display();
    }
    //test is now out of scope and should be destroyed

    ComplexNumber c4 = c1.negFrom(c2);
    
    printf("\n\n");
    c4.display();


    c4.neg(c2);
    c4.display();

    c4.negate();
    c4.display();

    c4.add(c2);
    c4.display();
    c4.negated();
    c4.display();

    


    while (true);
}

