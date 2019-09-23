#include "hmm.cpp"

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
#define EXPECT_TEST_INT(expect, actual) EXPECT_TEST_ACTUAL(expect==actual, expect, actual, "%f")

void testing_matrix(){
    Mymatrixplus t = initialization_tranistion_matrix();
    EXPECT_TEST_INT(0.8, t.findByNum(0,0));
}

void testing(){
    testing_matrix();
}

int main(){
    testing();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}