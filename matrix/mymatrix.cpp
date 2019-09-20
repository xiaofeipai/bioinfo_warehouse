class Mymatrix{
    private:
        unsigned int row, col;
        double** array;
        

        void free(){
            for(int i = 0; i!= row; i++){
                delete []array[i];
            }
            delete []array;
        }
    public:
        void change_matrix_value(double v, int i, int j);
        void reconstruction(unsigned int row, unsigned int col);
        double getvalue(int i, int j);
        Mymatrix();
        Mymatrix(unsigned int row, unsigned int col);
        ~Mymatrix();
};


void Mymatrix::change_matrix_value(double v, int i, int j){
    if(i < row&&j < col){
        array[i][j] = v;
    }
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

void Mymatrix::reconstruction(unsigned int row, unsigned int col){
    free();

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