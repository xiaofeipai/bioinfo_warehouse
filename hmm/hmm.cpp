#include "../mymatrixplus.cpp"
#include "hmm.c"
/*This is one example to find CpG land. */
Mymatrixplus initialization_tranistion_matrix(){
    Mymatrixplus t_matrix("YN", "YN");
    t_matrix.changevaluebynum(0,0, 0.8);
    t_matrix.changevaluebynum(0,1, 0.2);
    t_matrix.changevaluebynum(1,0, 0.1);
    t_matrix.changevaluebynum(1,1, 0.9);
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
    Mymatrixplus r_matrix("YN", onetstring);
    Mymatrixplus f_matrix("YN", onetstring);
    r_matrix.changevaluebynum(0, 0, 0.5*o_matrix.findbychar(r_matrix.getchar_s1(0), r_matrix.getchar_s2(0)));
    r_matrix.changevaluebynum(1, 0, 0.5*o_matrix.findbychar(r_matrix.getchar_s1(0), r_matrix.getchar_s2(1)));
    for(int i = 1; i != r_matrix.get_col(); i++)
        for(int j = 0; j != r_matrix.get_row(); j++){
            int Max = 0;
            for(int k = 0; k != r_matrix.get_row(); k++){
                double temp = r_matrix.findByNum(k, i - 1)*t_matrix.findByNum(k, j)*o_matrix.find_by_num_and_char(j, *(onetstring + i));
                if(temp > r_matrix.findByNum(j, i)){
                    Max = k;
                    r_matrix.changevaluebynum(j, i, temp);
                }
            }
            f_matrix.changevaluebynum(j, i);
        }
    mystring result("AA");
    return result;
}