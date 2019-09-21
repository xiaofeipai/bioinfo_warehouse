#ifndef _MYSTRING_MYSTRING_H__
#define _MYSTRING_MYSTRING_H__
class mystring {
    private:
        char *p;
        int length = 0;

        bool isvalid_letter(char m);
        void addchar(char p1, const char* p2);
        void addcharFront(char p1, const char* p2);
    public:
        int getlength();
        int find(char one);
        bool isvalid();
        bool isNone();
        const char* getstring();
        char getchar(int i);
        void addLetter(char one);
        void addLetterFront(char one);
        void addString(const char* k);
        void reconstruct(const char* k);
        mystring(const char* k);
        mystring();
        ~mystring();
};
#endif