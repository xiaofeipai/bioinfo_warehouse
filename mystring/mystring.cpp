#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

class mystring {
    private:
        char *p;
        int length = 0;

        bool isvalid_letter(char m){
            return((m == 'A')||(m == 'T')||(m == 'C')||(m == 'G')||(m == 'R')||
                (m == 'Y')||(m == 'K')||(m == 'S')||(m == 'M')||(m == 'H')||(m == 'B')||(m == 'V')||(m == 'D')||(m == 'N'));
        }
    
        void addchar(char p1, const char* p2){
            p = (char*)malloc(strlen(p2) + 2);
            strcpy(p, p2);
            *(p + strlen(p2)) = p1;
            *(p + strlen(p2) + 1) = '\0'; 
        }

        void addcharFront(char p1, const char* p2){
            p = (char*)malloc(strlen(p2) + 2);
            *p = p1; 
            *(p + 1) = '\0';
            strcat(p, p2);
        }

    public:
        int getlength();
        bool isvalid();
        bool isNone();
        const char* getstring();
        char getchar(int i);
        void addLetter(char one);
        void addLetterFront(char one);
        void addString(const char* k);
        mystring(const char* k);
        mystring();
        ~mystring();
};

int mystring::getlength(){
    return length;
}

bool mystring::isvalid(){
    int i = 0;
    while(*(p + i) != '\0'){
        if(!(isvalid_letter(*(p + i)))){
            return false;
        }
        i++;
    }
    return true;
}
bool mystring::isNone(){
    return length == 0;
}

const char* mystring::getstring(){
    return p;
}

char mystring::getchar(int i){
    if (i >= length){
        return '\0';
    }
    return *(p + i);
}

void mystring::addLetter(char one) {
    if(p){
        addchar(one, this->getstring());
    } else {
        p = (char*)malloc(2);
        *p = one;
        *(p + 1) = '\0';
    }
    length++;
}

void mystring::addLetterFront(char one) {
    if(p){
        addcharFront(one, this->getstring());
    } else {
        p = (char*)malloc(2);
        *p = one;
        *(p + 1) = '\0';
    }
    length++;
}

void mystring::addString(const char* k){
    if(length == 0){
        length = strlen(k);
        char* temp = (char*)malloc(strlen(k) + 1);
        strcpy(temp, k);
        for(int i = 0; i != length; i++)
            *(temp + i) = toupper(*(temp + i));
        p = (char*)malloc(strlen(k) + 1);
        strcpy(p, temp);
        free(temp);
    } else {
        char* temp = (char*)malloc(length + 1);
        strcpy(temp, p);
        length = length + strlen(k);
        p = (char*)malloc(length + 1);
        strcpy(p, temp);
        strcat(p, k);
        free(temp);
    }
}

mystring::mystring(const char* k) {
    length = strlen(k);
    char* temp = (char*)malloc(strlen(k) + 1);
    strcpy(temp, k);
    for(int i = 0; i != length; i++)
        *(temp + i) = toupper(*(temp + i));
    p = (char*)malloc(strlen(k) + 1);
    strcpy(p, temp);
    free(temp);
}

mystring::mystring(){
    p = (char*)malloc(1);
    *p = '\0';
}

mystring::~mystring() {
    free(p);
}
