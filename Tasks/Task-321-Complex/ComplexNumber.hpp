#ifndef ComplexNumber_hpp
#define ComplexNumber_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class ComplexNumber {
private:
    double real;
    double imag;
    
public:
    //Default constructor
    ComplexNumber() {
        this->real = 0.0;
        this->imag = 0.0;
    }
    
    //Constructor 2 - default of second parameter is 1 if not specified
    ComplexNumber(const double r, const double i = 0.0) {
        this->real = r;
        this->imag = i;
    }
    
    //Copy constructors
    ComplexNumber(const ComplexNumber& c) {
        this->imag = c.imag;
        this->real = c.real;
    }

    //Destructor
    ~ComplexNumber() {
        cout << "Bye'ee" << endl;
    }//this is run if there is an error
    
    //Read-only accessors
    double getReal() {
        return this->real;
    }

    double getImag() {
        return this->imag;
    }

    //Conjugate - verb, so perform in place
    void conjugate() {
        this->imag *= -1.0;
    }
    
    //Conjugated - adjective, so return new copy
    ComplexNumber conjugated() {
        return ComplexNumber(this->real, -1.0*this->imag);
    }


    
    //there are done in place
    //Add in place
    void add(const ComplexNumber& c) {
        this->real += c.real;
        this->imag += c.imag;
    }
    
    //this is done in place 
    void neg(const ComplexNumber& c){
        this->real -= c.real;
        this->imag -= c.imag;
    }
    

    void negate()
    {
        this->real -= this->real;
        this->imag -= this->imag; 
    }

    void mult(const ComplexNumber& c){
        this->real *= c.real;
        this->imag *= c.imag;
    }


    //these are copies
    //Add
    ComplexNumber addedTo(const ComplexNumber& c) {
        return ComplexNumber(this->real+c.real, this->imag+c.imag);
    }

    //this makes a copy
    ComplexNumber negFrom(const ComplexNumber& c){
        return ComplexNumber(this->real - c.real, this->imag-c.imag);
    }


    ComplexNumber multWith(const ComplexNumber& c){
        return ComplexNumber(this->real *= c.real, this->imag *= c.imag);
    }


    //this doesnt work well kind does as it is set back to the default but it is not a copy
    ComplexNumber negated(){
       return ComplexNumber(this->real -= this->real, this->imag-=this->imag);
    }
    


    //Display
    void display() {
        cout << this->real << " + " << this->imag << "j" << endl;
    }
    
};


#endif /* ComplexNumber_hpp */
