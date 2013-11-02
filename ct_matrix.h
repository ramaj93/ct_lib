#ifndef CT_MATRIX_H
#define CT_MATRIX_H

#include<stdarg.h>
#include"ct_math.h"

class Matrix{
    //private fields
    double *el;//pointer to all elements
    double *r; //pointer to a certain row
    double *c; //pointer to a certain column
    int size;
    int nRow;
    int nCol;
    bool err;

public:
    //info
    struct info{
        int row;
        int col;
    }*ldn;

    //constructors and destructors
    Matrix();
    Matrix(const int,int,...);
	~Matrix();
    //Methods
    double *getRow(int,int);
    void print(char);
    double *getCol(int,int);
    void rowTran(int,int);
    void rowMod(int,int,double[]);
    void gReduce();
    void jReduce();
    void getldn();
    //overloadable operators
    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);
    Matrix operator*(int);
    Matrix operator= (Matrix);

    //Setters and Getters
    double *eget();
    int get(char);
    void eset(double[]);
    void set(char, double);
    void inherits(Matrix);
    void inherits(Matrix*);

};
#endif // CT_MATRIX_H
