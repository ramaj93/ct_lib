#ifndef CT_MATH_H
#define CT_MATH_H
#define PI 3.14159265

#include <math.h>

namespace coreit{
	class ct_math;
}
   class ct_math{
    public:
        struct angle{
           double _angle;
           double radian;
           double toRadian();
           double toAngle();
           void operator=(double);
   };

   };

#endif // CT_MATH_H
