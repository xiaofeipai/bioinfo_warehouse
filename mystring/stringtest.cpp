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
    mystring i("AAACCC");
    EXPECT_TEST_STRING("AAACCC", i.getstring());
}

void testing(){
    testing_string_construction();
}



int main(){
    testing();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}