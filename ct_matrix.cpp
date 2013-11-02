//C++ learning project :Math/Matrix
//Authors:Ramadhan J.
//CoreIT sept 05 2013.

/*NOTES:
========
This class can support infinity size of Matrix size ie it depend on the buffer size
The algorithms used here for different computation are not general
Lessons:
========
From this project you must learn
1.Class declaration
2.Default and Common componets included in the class definition ie fields,methods,constructors...
3.Methods prototype and implimentations
4.The use of private and public fields or methods
5.Overloading operators
6.Variable arguments for function parameters
7.Using pointers
*/
#include<iostream>
#include"ct_matrix.h"


//This constructor take in a size,a row and the elements
//We use a variable args list to take in parameters
Matrix::Matrix(const int _size, int _row,...){
    size = _size;
    nRow = _row;
    nCol = _size/_row;
    el = new double[_size];
    va_list ap;

    va_start(ap,_size);
    //check to see if the size is correct
    if(_size%_row > 0){
        err = true;
        std::cerr<<"ERROR:This matrix wasn't created succesfully\n";
        std::cerr<<"CAUSE:Unmatching Row and Col for the Size You specified!\n";
        system("pause");
    }
    else{
        for(int i = 0;i<_size;i++){
            el[i]= va_arg(ap,double);
            std::cout<<va_arg(ap,double);
            //std::cout<<el[i]<<std::endl;
        }
        err = false;
        }
    va_end(ap);

}
Matrix::Matrix(){
    //el={0};
    size = 0;
    nRow = 0;
    nCol = 0;
    err = false;
}

Matrix::~Matrix()
{
	//memory management ie. delete all the pointers you created in the stack(using 'new')
	delete r;
	delete c;
	delete el;
}
void Matrix::set(char opt,double val){
    switch(opt){
    case('r'): nRow = val;
        break;
    case('c'): nCol = val;
        break;
    case('e'): {
        if(val==0) err=true;
                else err=false;
    }
        break;
    case('s'): size = val;
        break;
    }
}

double *Matrix::eget(){
    return el  //return the pointer to our element array
}
int Matrix::get(char opt){
    switch(opt){
    case('r'):return nRow;
        break;
    case('c'):return nCol;
        break;
    case('e'):return err;
        break;
    case('s'):return size;
        break;
    default:return 0;
        break;
    }
}
void Matrix::eset(double se[]){
    el = new double[size];
    for(int k=0;k<size;k++){
        el[k]=se[k];
    }
}

void Matrix::inherits(Matrix b){
    nRow = b.get('r');
    nCol = b.get('c');
    size = nRow*nCol;
    err = b.get('e');
    el = new double[size];
}

void Matrix::inherits(Matrix *b){
    nRow = (b)->get('r');
    nCol = (b)->get('c');
    size = nRow*nCol;
    err = (b)->get('e');
    el = new double[size];
}

double *Matrix::getRow(int rn,int opt){
    r = new double[nCol];
    int k = 0;
    for(int i = nCol*(rn);i<(rn+1)*nCol;i++){
        if(opt!=0){
        r[k] = el[i];
        k++;
        }
        else {
            //std::cout<<"gr "<<*(el+i)<<" "<<i<<std::endl;
            return (el+i);
            break;
        }
    }
    return r;
}

double *Matrix::getCol(int cn,int opt){
    c = new double [nRow];
    int k = 0;
    for(int i=0;i<size;i++){
        for(int rn = 0;rn<nRow;rn++){
            if(i==(nCol*(rn)+(cn))){
                if(opt !=0){
                c[k]=el[i];
                 k++;
                }
                else {
                    return (el+i); //return the adress of first element in a column
                    break;
                }
            }
        }
    }
    return c;
}

Matrix Matrix::operator +(Matrix b){
    Matrix sum;
    if(size != b.get('s')){
        sum.set('e',0);
        //log error
    }
    else{
        sum.inherits(this);
        double *elb;
        double els[size];
        elb = b.eget();
        for(int k=0;k<size;k++){
            els[k] = el[k] + *(elb+k);
        }
        sum.eset(els);
    }
    return sum;
}

Matrix Matrix::operator -(Matrix b){
    Matrix sum;
    if(size != b.get('s') ||err){
        //log error
        sum.inherits(this);
    }
    else{
        sum.inherits(this);
        double *elb;
        double els[size];
        elb = b.eget();
        for(int k=0;k<size;k++){
            els[k] = el[k] - *(elb+k);
        }
        sum.eset(els);
    }
    return sum;
}

Matrix Matrix::operator =(Matrix b){
    this->inherits(b);
    eset(b.eget());
}

Matrix Matrix::operator *(Matrix b){
    Matrix pd;
    int rb = b.get('r'); //no of rows for matrix b
    int cb = b.get('c'); //no of column for matrix b 

    if((nCol!=rb)){
        //log error
        std::cout<<"error\n";
        pd.set('e',false);
    }
    else{       
        pd.inherits(this);//NOT REALLY some manual setting is required here
        pd.set('r',nRow);
        pd.set('c',cb);
        pd.set('s',nRow*cb);
        double *te;
        double *teb;
        int m=0;
        double sum=0;
        for(int i=0;i<nRow;i++){
            te = getRow(i,1);
            for(int j=0;j<cb;j++){
                teb = b.getCol(j,1);
                 sum = 0;
                 for(int k=0;k<rb;k++){
                     sum += (*(te+k) * (*(teb+k)));
                    //*(pd.eget()+m) += *(te+k)*(*(teb+k));
                }
                *(pd.eget()+m) = sum;
                m++;
            }
        }
    }
return pd;
}

Matrix Matrix::operator *(int num){
    Matrix pd;
    pd.inherits(this);
    //long els[size];
    for(int i = 0;i<size;i++){
        //els[k] = num*(el[i]);
        *(pd.eget()+i)= num*(el[i]);  //!!!getting used to pointers
    }
    //pd.eset(els);
    return pd;
}

void Matrix::rowTran(int frn,int srn){
    double *fr = getRow(frn,0);
    double *sr = getRow(srn,0);
    double tmp[nCol];
    for(int i = 0;i<nCol;i++){
        tmp[i] = *(fr+i);
        *(fr+i) = *(sr+i);
        *(sr+i) = tmp[i];
    }
}

void Matrix::rowMod(int rn,int co,double mr[]){
    double *rp = getRow(rn,0);

    for(int i=0;i<nRow;i++){
        *(rp+i)+=co*mr[i];
    }
}

void Matrix::getldn(){
    ldn = new info[nRow];
    for(int i=0;i<nRow;i++){
        for(int k = nCol*(i);k<(i+1)*nCol;k++){
            if(el[k]!=0){
                ldn[i].col = k;
                ldn[i].row = el[k];
                break;
            }
    	}

	}

}

void Matrix::gReduce(){
	//apply gaussian reduction algorithm here
}

void::Matrix::print(char opt){
    switch (opt){
    case 'e':{
        if(!err){
            int k=1;
        for(int i = 0;i<size;i++){
            std::cout<<el[i]<<" ";
            if(i==(k*nCol-1)||i==(size-1)){
                k+=1;
                std::cout<<std::endl;
            }
        }
        }
        else{
            std::cerr<<"ERROR:Cannot Display Elements\n";
            std::cerr<<"CAUSE:This matrix wasn't created succesfully\n";
        }
    }
    break;
    }
}


