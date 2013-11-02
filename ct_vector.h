#ifndef CT_VECTOR_H
#define CT_VECTOR_H

class vector{
    //private fields
    double x;
    double y;
    double z;
    int dim;
    double det;
    bool err;
    double magnitude;
    public:
    //constuctors
    vector();
    vector(double,double,int _dim=2,double _z=0);

    //methods

    vector Cross(double,double,double);
    vector Cross(vector);

    double Dot(double,double,double);
    double Dot(vector);

    double Magnitude(double,double,double);
    double Magnitude(vector);

    void print(char);

    //getters and setters
    double get(char);
    void set(char,double,bool);

    //overloadable operators
    vector operator+ (vector);
    vector operator- (vector);
    vector operator* (vector);
    vector operator= (vector);
    vector operator^ (vector);
};
#endif // CT_VECTOR_H
