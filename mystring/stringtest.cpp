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

#define EXPECT_TESTING_ADD(expect, input1, input2)\
    do{\
        mystring i1(input1);\
        mystring i2(input2);\
        i1 = i1 + i2;\
        EXPECT_TEST_STRING(expect, i1.getstring());\
    }while(0)

void testing_string_add(){
    EXPECT_TESTING_ADD("AACC", "aa", "cc");
    EXPECT_TESTING_ADD("AAGG", "aa", "GG");
    EXPECT_TESTING_ADD("AAMMM", "aa", "mmm");
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

void testing(){
    testing_string_construction();
    testing_string_valid();
    testing_string_add();
    testing_letter_add();
}

int main(){
    testing();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}