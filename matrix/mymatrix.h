#ifndef _MATRIX_MYMATRIX_H__
#define _MATRIX_MYMATRIX_H__
class Mymatrix{
    private:
        unsigned int row, col;
        double** array;

        void free();
    public:
        void change_matrix_value(double v, int i, int j);
        void reconstruction(unsigned int row, unsigned int col);
        double getvalue(int i, int j);
        Mymatrix();
        Mymatrix(unsigned int row, unsigned int col);
        ~Mymatrix();
};
#endif