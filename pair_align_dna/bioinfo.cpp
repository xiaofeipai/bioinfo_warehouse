#include "bioinfo.h"
#include <string>
#include "..\mystring\mystring.cpp"
#include <iostream>
#define MAX(a, b) a>b?(a):(b)

int gap = -2;
int align_letter(char one, char two){
    if(one == two)
        return 1;
    else
        return -1;
}

bool if_null(const char* string_one){
    if(*string_one == '\0')
        return 1;
    else
        return 0;
}
int get_string_length(const char* string_one){
    int i = 0;
    while(*(string_one + i) != '\0')
        i++;
    return i;
}

run_status Pairwise_align_dna(const char* string_one, const char * string_two, result* string_result){
    if(if_null(string_one)||if_null(string_two)){
        return STRING_NULL;
    }
    mystring mystring_one(string_one);
    mystring mystring_two(string_two);
    int string_one_length = mystring_one.getlength() + 1; 
    int string_two_length = mystring_two.getlength() + 1;
    
    int M1[string_one_length][string_two_length];
    int M2[string_one_length][string_two_length];
    /*matrix initialization refer to step one*/
    for (int i = 0; i != string_one_length; i++){
        M1[i][0] = i*gap;
        M2[i][0] = FROM_UP;
    }
    for (int i = 0; i != string_two_length; i++){
        M1[0][i] = i*gap;
        M2[0][i] = FROM_LEFT;
    }
    
    /*matrix calculation refer to step two*/
    for(int i = 1; i != string_one_length; i++){
        for(int j = 1; j != string_two_length; j++){
            M1[i][j] = MAX(M1[i - 1][j - 1] + align_letter(mystring_one.getchar(i), mystring_two.getchar(j)), M1[i - 1][j] + gap);
            M1[i][j] = MAX(M1[i][j], M1[i][j - 1] + gap);
            if(M1[i][j] == M1[i - 1][j] + gap)
                M2[i][j] = FROM_UP;
            else if(M1[i][j] == M1[i][j - 1] + gap)
                M2[i][j] = FROM_LEFT;
            else
                M2[i][j] = FROM_DIAGONAL;
        }
    }
    
    /*matrix trace back refer to step three*/
    int i_MAX = string_one_length - 1;
    int j_MAX = string_two_length - 1;
    for (int i = 0; i != string_one_length; i++){
        if(M1[i][string_two_length - 1] > M1[i_MAX][j_MAX]){
            i_MAX = i;
            j_MAX = string_one_length - 1;
        }
    }
    for (int j = 0; j != string_two_length; j++){
        
        if(M1[string_one_length - 1][j] > M1[i_MAX][j_MAX]){
            i_MAX = string_two_length - 1;
            j_MAX = j;
        }
    }
    mystring return_string;
    
    while(1){
        if(M2[i_MAX][j_MAX] == FROM_LEFT){
            return_string.addLetter(mystring_two.getchar(j_MAX - 1));
            j_MAX--; 
        } else if(M2[i_MAX][j_MAX] == FROM_UP){
            i_MAX--;
            return_string.addLetter('-');
        } else {
            return_string.addLetter(mystring_two.getchar(j_MAX - 1));
            j_MAX --;
            i_MAX --;
        }

        if(i_MAX <= 0&&j_MAX <= 0){
            break;
        }
    }
    string_result->r = PAIR_ALIGN_DNA;
    string_result->final_result = return_string.getstring();
    printf(string_result->final_result);
    return RUN_OK;

}