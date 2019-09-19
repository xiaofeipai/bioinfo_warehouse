#include "mymatrix.cpp"
#include <stdio.h>

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

#define EXPECT_TEST_INT(expect, actual) EXPECT_TEST_ACTUAL(expect == actual, expect, actual, "%d")

void test_construction(){
    Mymatrix m(4, 4);
    EXPECT_TEST_INT(0, m.getvalue(1,1));
}

void test_change_value(){
    Mymatrix m(4,4);
    EXPECT_TEST_INT(0, m.getvalue(1,1));
    m.change_matrix_value(1.0, 1, 1);
    EXPECT_TEST_INT(1.0, m.getvalue(1,1));

}

void testing(){
    test_construction();
    test_change_value();
}


int main(){
    testing();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}