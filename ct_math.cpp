#include"ct_math.h"

double ct_math::angle:: toRadian(){
    radian = (_angle*PI)/180;
    return radian;
}

double ct_math::angle::toAngle(){
    _angle = (radian*180)/PI;
    return _angle;
}

void ct_math::angle::operator =(double rad){
    radian = rad;
}
