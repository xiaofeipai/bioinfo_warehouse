#include "mymatrix.h"

void Mymatrix::free(){
    for(int i = 0; i!= row; i++){
                delete []array[i];
    }
    delete []array;
}

void Mymatrix::change_matrix_value(double v, int i, int j){
    if(i < row&&j < col){
        array[i][j] = v;
    }
}

void Mymatrix::reconstruction(unsigned int i_row, unsigned int i_col){
    free();
    col = i_col;
    row = i_row;
    array = new double*[row];
    for(int i = 0; i != row; i++){
        array[i] = new double[col];
    }
    for(int i = 0; i != row; i++){
        for(int j = 0; j != col; j++)
            array[i][j] = 0.0;
    }
}

int Mymatrix::get_row(){
    return row;
}

int Mymatrix::get_col(){
    return col;
}

double Mymatrix::getvalue(int i, int j){
    if(i < row&&j < col){
        return array[i][j];
    }
    return 0;
}

Mymatrix::Mymatrix(){
        row = 0;
        col = 0;
        array = new double*[1];
        array[0] = new double[1];
        array[0][0] = 0;
}

Mymatrix::Mymatrix(unsigned int i_row, unsigned int i_col){
    col = i_col;
    row = i_row;
    array = new double*[row];
    for(int i = 0; i != row; i++){
        array[i] = new double[col];
    }
    for(int i = 0; i != row; i++){
        for(int j = 0; j != col; j++)
            array[i][j] = 0.0;
    }
}

Mymatrix:: ~Mymatrix(){
    for(int i = 0; i!= row; i++){
        delete []array[i];
    }
    delete []array;
}