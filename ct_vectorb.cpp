//C++ learning project :Math/Vector
//Authors:Ramadhan J. ,Ramadhan N.
//CoreIT sept 03 2013.

/*NOTES:
========
This class only support up to a 3 dimensional vector
The algorithms used here for different computation are not general,i.e should only
be used for 2d and 3d vectors
Lessons:
========
From this project you must learn 
1.class declaration
2.Default and Common componets included in the class definition ie fields,methods,constructors...
3.Methods prototype and definition
4.The use of private and public fields or methods
5.Overloading operators
6.Default parameters in functions
*/

#include<iostream>
#include<math.h>
#include"ct_vector.h"

//we have a default value of z so that the 2d vector can also be incorporated
vector::vector(float _x,float _y,int _dim=0,float _z=0){
	if(_dim==3){
		x=_x;
		y=_y;
		z=_z;
		dim = _dim;
		magnitude=Magnitude(x,y,z);
	}
	else{
		x =_x;
		y =_y;
		dim =_dim;
		magnitude=Magnitude(x,y,0);
	}

	err = false;
}
vector vector::operator=(vector b){
	x=b.get('x');
	y=b.get('y');
	z=b.get('z');
	dim=b.get('d');
	det=b.get('t');
	err=b.get('e');
}


void vector::set(char com ,float value=0,bool _err=false){
	if(com =='x') x = value;
	else if(com =='y') y = value;
	else if(com =='z') z = value;
	else if(com =='d') dim = value;
	else if(com =='e') err = _err;
}
float vector::get(char com){
	switch (com){
		case('x'):return x;
		break;
		case('y'):return y;
		break;
		case('z'):return z;
		break;
		case('d'):return dim;
		break;
		case('e'):return err;
		break;
		case('t'):return det;
		break;
		default:return 0;
		break;
	}
}

vector vector::operator+(vector b){
	vector sum(0,0,0,0);
	sum.set('x',(x+b.get('x')));
	sum.set('y',(y+b.get('y')));
	sum.set('z',(z+b.get('z')));
	return sum;
}

vector vector::operator-(vector b){
	vector sum(0,0,0,0);
	sum.set('x',(x-b.get('x')));
	sum.set('y',(y-b.get('y')));
	sum.set('z',(z-b.get('z')));
	return sum;
}
//three parameters with  a z-axis default parameter initialized to 0
vector vector::Cross(float _x,float _y,float _z=0){
	vector cp(0,0,0,0);
		if(dim == 2){
			cp.set('d',(x*_y)-(y*_x));
			cp.set('e',false);
			cp.set('d',2);
		}
		else{
			cp.set('x',((y*_z)-(_y*z)));
			cp.set('y',-((x*_z)-(_x*z)));
			cp.set('z',((x*_y)-(_x*y)));
			cp.set('e',false);
			cp.set('d',3);
		}
		return cp;
}

vector vector::Cross(vector _vc){
	vector cp(0,0,0,0);
	if(dim ==_vc.dim){
		if(dim == 2){
			cp.set('d',(x*_vc.get('y'))-(y*_vc.get('x')));
			cp.set('e',false);
		}
		else{
			cp.set('x',(y*_vc.get('z')-(_vc.get('y')*z)));
			cp.set('y',-((x*_vc.get('z')-(_vc.get('x')*z))));
			cp.set('z',(x*_vc.get('y'))-(_vc.get('x')*y));
			cp.set('e',false);
		}
	}
	else err = true;
	return cp;
}

vector vector::operator^(vector b){
	return Cross(b);
}

float vector::Dot(float _x,float _y,float _z=0){
	return x*_x + y*_y + z*_z;
}
float vector::Dot(vector _vc){
	return x* _vc.get('x')+y*_vc.get('y')+z*_vc.get('z');
}

float vector::Magnitude(float _x=0,float _y=0,float _z=0){
	if (_x==0&&_y==0&&_z==0){
		return sqrtl((x*x)+(y*y)+(z*z));
	}
	else
	{
		return sqrtl((_x*_x)+(_y*_y)+(_z*_z));
	} 
}
float vector::Magnitude(vector _vc){
	//powl() or pow() is a math function that take in a base and an exponent and return a power
		return sqrtl(powl(_vc.get('x'),2.0)+powl(_vc.get('y'),2.0)+powl(_vc.get('z'),2.0));
}
void vector::print(char com){
	if(com == 'v') {
		std::cout<<"x= "<<x<<" y= "<<y<<" z= "<<z<<std::endl;
	}
	else if(com == 'm') std::cout<<"Magnitude is: "<<0;
	else if(com == 'd') std::cout<<"Dimension is:"<<dim;
}

