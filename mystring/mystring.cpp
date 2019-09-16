#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

class mystring {
    private:
        char *p;
        int length = 0;
        bool isvalid_letter(char m){
            return(m == 'A'||m == 'T'||m == 'C'|| m == 'G'||m == 'R'||m == 'Y'||m == 'K'||
                m == 'S'||m == 'M'||m == 'H'||m == 'B'||m == 'V'||m == 'D'||m == 'N');
        }
        void addstring(const char* p1, const char* p2){
            p = (char*)malloc(strlen(p1) + strlen(p2) + 1);
            strcpy(p, p1);
            strcat(p, p2);
        }

    public:
        int getlength();
        bool isvalid();
        const char* getstring();
        char getchar();
        mystring operator+( mystring  one){
            mystring result;
            result.addstring(this->getstring(), one.getstring());
            return result;
        };
        mystring(const char* k);
        mystring();
        ~mystring();
};

int mystring::getlength(){
    return length;
}

bool mystring::isvalid(){
    int i = 0;
    while(*(p + i) == '\0'){
        if(isvalid_letter(*(p + i))){
            return false;
        }
        i++;
    }
    return true;
}

const char* mystring::getstring(){
    return p;
}

char mystring::getchar(){
    return *p;
}

mystring::mystring(const char* k) {
    
    length = strlen(k);
    p = (char*)malloc(strlen(k) + 1);
    strcpy(p, k);
}

mystring::mystring(){
    p = NULL;
}

mystring::~mystring() {
    free(p);
}


