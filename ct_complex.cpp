#include "ct_complex.h"



Complex::Complex(double _re, double _im){
    props.re = _re;
    props.im = _im;
}
Complex::Complex(){
    props.im = 0;
    props.re = 0;
}

void Complex::set(double r,double i){
    props.re = r;
    props.im = i;
}

Complex Complex::operator+(Complex b){
    Complex sum;
    sum.set(props.re + b.get().re,props.im + b.get().im);
    return sum;
}
void Complex::operator =(Complex b){
    props.re = b.get().re;
    props.im = b.get().im;
    props.arg = b.get().arg;
    props.abs =b.get().abs;
    props.err = b.get().err;
}
Complex Complex::operator *(Complex b){
    Complex pd;
    pd.set((props.re*b.get().re-props.im*b.get().im),(props.re*b.get().im + b.get().re*props.im));
    return pd;
}
Complex Complex::operator *(Complex *b){
    Complex pd;
    pd.set((props.re*b->get().re-props.im*b->get().im),(props.re*b->get().im + b->get().re*props.im));
    return pd;
}
Complex Complex::operator *(double n){
    Complex pd;
    pd.set(n*props.re,n*props.im);
    return pd;
}

Complex Complex::operator /(Complex b){
    Complex dv;
    Complex a = b.conjugate()*this;
    Complex c = b.conjugate() * b;
    dv.set(a.get().re/c.get().re,a.get().im/c.get().re);
    return dv;
}

Complex::_props Complex::get(){
    _props prop;
    prop.re = props.re;
    prop.im = props.im;
    prop.abs = props.abs;
    prop.arg = props.arg;

    return prop;
}
void Complex::absArg(){
    props.abs = (sqrt(powl(props.re,2.0) + powl(props.im,2.0)));
    props.arg.radian = atan(props.im/props.re);
}

Complex Complex::conjugate(){
    Complex cg;
    cg.set(props.re,-props.im);
    return cg;
}

void Complex::print(){
    if(!props.err){
        if(props.im>0){
            std::cout<<props.re<<" + "<<props.im<<"i"<<std::endl;
        }
        else
        {
            std::cout<<props.re<<" - "<<-1*props.im<<"i"<<std::endl;
        }
    }
}
