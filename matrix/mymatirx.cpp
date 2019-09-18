class Mymatrix{
    unsigned int row, col;
    double** array;

    Mymatrix(){
        row = 0;
        col = 0;
        **array = new double*[1];
        array[0] = new double[1];
        array[0][0] = 0;
    }
    Mymatrix(unsigned int row, unsigned int col){
        **array = new double*[row];
        for(int i = 0; i != row; i++){
            array[i] = new double[col];
        }
        for(int i = 0; i != row; i++){
            for(int j = 0; j != col; j++)
                array[i][j] = 0.0;
        }
    }
}