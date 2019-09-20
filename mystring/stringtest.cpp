#include "mystring.cpp"

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

#define EXPECT_TEST_ACTUAL(equality, expect, actual, format) \
    do{\
        test_count++;\
        if(equality)\
            test_pass++;\
        else{\
            fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
            main_ret = 1;\
        }\
    }while(0)

#define EXPECT_TEST_STRING(expect, actual) EXPECT_TEST_ACTUAL(!strcmp(expect, actual), expect, actual, "%s")
#define EXPECT_TEST_INT(expect, actual) EXPECT_TEST_ACTUAL(expect==actual, expect, actual, "%d")

void testing_string_construction(){
    mystring i("aaaccc");
    EXPECT_TEST_STRING("AAACCC", i.getstring());
}

#define EXPECT_TESTING_VALID(expect, input)\
    do{\
        mystring i(input);\
        EXPECT_TEST_ACTUAL(expect == i.isvalid(), expect, i.isvalid(), "%s");\
    }while(0)

void testing_string_valid(){
    EXPECT_TESTING_VALID(1, "aaaa");
    EXPECT_TESTING_VALID(false, "%");
}

#define EXPECT_TESTING_ADDCHAR(expect, input1, input2)\
    do{\
        mystring i1(input1);\
        i1.addLetter(input2);\
        EXPECT_TEST_STRING(expect, i1.getstring());\
    }while(0)

void testing_letter_add(){
    EXPECT_TESTING_ADDCHAR("AAGG", "AAG",'G');
}

void testing_null(){
    mystring m;
    EXPECT_TEST_ACTUAL(m.isNone(),1,0, "%d");
}

void EXPECT_TESTING_ADDSTRING(const char* expect,const char* input1,const char* input2){
        mystring ms1(input1);
        mystring ms2(input2);
        ms1.addString(ms2.getstring());
        EXPECT_TEST_STRING(expect, ms1.getstring());
    }

void testing_add_string(){
    EXPECT_TESTING_ADDSTRING("AACC", "AA", "CC");
}

#define EXPECT_TESTING_RECONSTRUCT(expect1, expect2, input1, input2)\
    do{\
        mystring i1(input1);\
        EXPECT_TEST_STRING(expect1, i1.getstring());\
        i1.reconstruct(input2);\
        EXPECT_TEST_STRING(expect2, i1.getstring());\
    }while(0)

void testing_reconstruction(){
    EXPECT_TESTING_RECONSTRUCT("AA","CC","AA","CC");
}

#define EXPECT_TESTING_FIND(expect, actual)\
    do{\
        mystring i1("ACTG");\
        EXPECT_TEST_INT(expect, i1.find(actual));\
    }while(0)

void testing_find(){
    EXPECT_TESTING_FIND(0, 'A');

}
void testing(){
    testing_string_construction();
    testing_null();
    testing_string_valid();
    testing_letter_add();
    testing_add_string();
    testing_find();
}

int main(){
    testing();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}