#include<iostream>
#include<math.h>
//#include<stdarg.h>
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
        std::cout<<"ERROR:This matrix wasnt created succesfully\n";
        std::cout<<"CAUSE:Unmatching Row and Col for the Size You specified!\n";
    }
    else{
        for(int i = 0;i<_size;i++){
            el[i]= va_arg(ap,long);
        }
        err = false;
        }
    va_end(ap);

}
void::Matrix::print(char com){
    switch (com){
    case 'e':{
        if(!err){
        for(int i = 0;i<size;i++){
            std::cout<<el[i]<<" ";
            if(i==nCol||i==(size-1)) std::cout<<std::endl;
        }
        }
        else{

            std::cout<<"ERROR:Cannot Display Elements\n";
            std::cout<<"CAUSE:This matrix wasn't created succesfully\n";
        }
    }
    break;
    }
}

