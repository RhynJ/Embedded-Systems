#ifndef __complexSum__
#define __complexSum__

    typedef struct {
    double real;
    double imag;
    } ComplexNumber_C;

ComplexNumber_C complexAdd(const ComplexNumber_C a, const ComplexNumber_C b);
void complexDisplay(const char *strName, const ComplexNumber_C u) ;


#endif