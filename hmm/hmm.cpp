#include "../mymatrixplus.cpp"
#include "hmm.c"

/*This is one example to find CpG land. */
Mymatrixplus initialization_tranistion_matrix(){
    Mymatrixplus t_matrix("YN", "YN");
    t_matrix.changevaluebynum(0,0, 0.8);
    t_matrix.changevaluebynum(0,1, 0.2);
    t_matrix.changevaluebynum(1,0, 0.9);
    t_matrix.changevaluebynum(1,1, 0.1);
    return t_matrix;
}

Mymatrixplus initialization_omission_matrix(){
    Mymatrixplus t_matrix("YN", "ATCG");
    t_matrix.changevaluebynum(0,0, 0.1);
    t_matrix.changevaluebynum(0,1, 0.1);
    t_matrix.changevaluebynum(0,2, 0.4);
    t_matrix.changevaluebynum(0,3, 0.4);
    t_matrix.changevaluebynum(1,0, 0.25);
    t_matrix.changevaluebynum(1,1, 0.25);
    t_matrix.changevaluebynum(1,2, 0.25);
    t_matrix.changevaluebynum(1,3, 0.25);
    return t_matrix;
}
/*prediction of the sequence i use the cpg land*/
mystring predict_sequence(const char* onetstring){
    Mymatrixplus t_matrix = initialization_tranistion_matrix();
    Mymatrixplus o_matrix = initialization_omission_matrix();
    return "pp";
}