#include "./mystring/mystring.cpp"
#include "./matrix/mymatrix.cpp"

class Mymatrixplus{
    private:
        Mymatrix m1;
        mystring s1;
        mystring s2;
    public:
        char getchar_s1(int i);
        char getchar_s2(int i);
        int get_row();
        int get_col();
        double findByNum(unsigned int i,unsigned int j);
        double findbychar(char one, char two);
        double find_by_num_and_char(unsigned int i, char two);
        void changevaluebynum(unsigned int i,unsigned int j, double v);
        void changevaluebychar(char one, char two, double v);
        Mymatrixplus(const char* string_one, const char* string_two);
        ~Mymatrixplus();
};

char Mymatrixplus::getchar_s1(int i){
    return s1.getchar(i);
}

char Mymatrixplus::getchar_s2(int i){
    return s2.getchar(i);
}

int Mymatrixplus::get_row(){
    return m1.get_row();
}

int Mymatrixplus::get_col(){
    return m1.get_col();
}
double Mymatrixplus::findByNum(unsigned int i, unsigned int j){
    return m1.getvalue(i, j);
}

double Mymatrixplus::findbychar(char one, char two){
    if(s1.find(one) != -1 && s2.find(two) != -1){
        return m1.getvalue(s1.find(one), s2.find(two));
    } else {
        return -1;
    }
}

double Mymatrixplus::find_by_num_and_char(unsigned int i, char two){
    if(s2.find(one) != -1){
        return m1.getvalue(i, s2.find(two));
    } else {
        return -1;
    }
}

void Mymatrixplus::changevaluebynum(unsigned int i,unsigned int j, double v){
    m1.change_matrix_value(v, i, j);
}

void Mymatrixplus::changevaluebychar(char one, char two, double v){
    if(s1.find(one) != -1 && s2.find(two) != -1){
        m1.change_matrix_value(v, s1.find(one), s2.find(two));
    }
}

Mymatrixplus::Mymatrixplus(const char* string_one, const char* string_two){
    s1.addString(string_one);
    s2.addString(string_two);
    m1.reconstruction(s1.getlength() + 1, s2.getlength() + 1);
}

Mymatrixplus::~Mymatrixplus(){
    s1.~mystring();
    s2.~mystring();
    m1.~Mymatrix();
}