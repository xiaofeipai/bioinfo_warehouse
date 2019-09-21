#include "bioinfo.h"
#include "..\mystring\mystring.cpp"
#include "..\matrix\mymatrix.cpp"
#include <iostream>
#define MAX(a, b) a>b?(a):(b)

int gap = -2;
int align_letter(char one, char two){
    if(one == two)
        return 1;
    else
        return -1;
}

run_status Pairwise_align_dna(mystring mystring_one, mystring mystring_two, result* string_result){
    if(mystring_one.isNone()||mystring_two.isNone()){
        return STRING_NULL;
    }
    int string_one_length = mystring_one.getlength() + 1; 
    int string_two_length = mystring_two.getlength() + 1;
    Mymatrix M1(string_one_length, string_two_length);
    Mymatrix M2(string_one_length, string_two_length);
    /*matrix initialization refer to step one*/
    for (int i = 0; i != string_one_length; i++){
        M1.change_matrix_value(i * gap, i, 0);
        M2.change_matrix_value(FROM_UP, i, 0);
    }
    for (int i = 0; i != string_two_length; i++){
        M1.change_matrix_value(i * gap, 0, i);
        M2.change_matrix_value(FROM_LEFT, 0, i);
    }
    
    /*matrix calculation refer to step two*/
    for(int i = 1; i != string_one_length; i++){
        for(int j = 1; j != string_two_length; j++){
            M1.change_matrix_value(MAX(M1.getvalue(i - 1, j - 1) + 
                align_letter(mystring_one.getchar(i), mystring_two.getchar(j)), M1.getvalue(i - 1, j) + gap), i, j);
            M1.change_matrix_value(MAX(M1.getvalue(i, j), M1.getvalue(i, j - 1) + gap), i, j);
            if(M1.getvalue(i, j) == M1.getvalue(i - 1, j) + gap)
                M2.change_matrix_value(FROM_UP, i, j);
            else if(M1.getvalue(i, j) == M1.getvalue(i, j - 1) + gap)
                M2.change_matrix_value(FROM_LEFT, i, j);
            else
                M2.change_matrix_value(FROM_DIAGONAL, i, j);
        }
    }
    
    /*matrix trace back refer to step three*/
    int i_MAX = string_one_length - 1;
    int j_MAX = string_two_length - 1;
    for (int i = 0; i != string_one_length; i++){
        if(M1.getvalue(i, string_two_length - 1)> M1.getvalue(i_MAX, j_MAX)){
            i_MAX = i;
            j_MAX = string_one_length - 1;
        }
    }
    for (int j = 0; j != string_two_length; j++){
        if(M1.getvalue(string_one_length - 1, j)> M1.getvalue(i_MAX, j_MAX)){
            i_MAX = string_two_length - 1;
            j_MAX = j;
        }
    }
    mystring return_string;
    
    while(1){
        if(M2.getvalue(i_MAX, j_MAX) == FROM_LEFT){
            return_string.addLetterFront(mystring_two.getchar(j_MAX - 1));
            j_MAX--; 
        } else if(M2.getvalue(i_MAX, j_MAX) == FROM_UP){
            i_MAX--;
            return_string.addLetterFront('-');
        } else {
            return_string.addLetterFront(mystring_two.getchar(j_MAX - 1));
            j_MAX --;
            i_MAX --;
        }

        if(i_MAX <= 0&&j_MAX <= 0){
            break;
        }
    }
    string_result->r = PAIR_ALIGN_DNA;
    string_result->final_result = (char*)malloc(strlen(return_string.getstring()) + 1);
    strcpy(string_result->final_result, return_string.getstring());
    return RUN_OK;
}
