#ifndef CT_COMPLEX_H
#define CT_COMPLEX_H

#include<iostream>
#include"ct_math.h"

class Complex: public ct_math{
    struct _props{
        double re;
        double im;
        double abs;
        angle arg;
        bool err;
    }props;
public:
    //constructor
    Complex(double,double);
    Complex();
    //methods
    void print();
    void absArg();
    Complex conjugate();

    //getters and setters
    _props get();
    void set(double,double);

    //overloadable operators
    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
    void operator=(Complex);
    Complex operator*(double);
    Complex operator*(Complex*);
    Complex operator/(Complex);
};

#endif // CT_COMPLEX_H
