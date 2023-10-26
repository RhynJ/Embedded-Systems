#include "mbed.h"
#include <cmath>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

class DoubleNumber {
private:

protected:
    double _real;

public:
    //Designated constructor
    DoubleNumber(double r) {
        _real = r;
        cout << "This is the constructor of Base" << endl;
    }

    //Convenience constructor
    DoubleNumber() : DoubleNumber(0.0) { }

    //Magnitude
    double magnitude() {
        return fabs(_real);
    }

    //Three overloaded functions
    void setValue(double u) {
        _real = u;
    }
    void setValue(int u) {
        _real = (double)u;
    }
    void setValue(string strVal) {
        _real = stod(strVal);
    }


    double getValue() {
        return _real;
    }

    string asString() {
        return to_string(_real);
    }
};


int main()
{
    //Constructor Function overloading 
    //pass it a float a float gets set
    DoubleNumber n0(1.0);
    DoubleNumber n1;
    DoubleNumber n2;
    DoubleNumber n3;

    //setValue function overloading  
    //pass it an int an int gets set 
    n1.setValue(10);
    //pass it a string it gets converted to a float 
    n2.setValue("-3.0");


    //it wont let you
    //n0.setValue(n3);

    cout << n0.getValue() + n1.getValue() + n2.getValue() << endl;

    while (true) {

    }
}

