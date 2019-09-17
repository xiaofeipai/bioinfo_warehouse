#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bioinfo.cpp"

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

#define TEST_STRING(expect, actual) EXPECT_TEST_ACTUAL(!strcmp(expect, actual), expect, actual, "%s")
#define TEST_INT(expect, actual) EXPECT_TEST_ACTUAL((expect) == (actual), expect, actual, "%d")


static void if_null_test(){
    TEST_INT(0, if_null("0"));
    TEST_INT(1, if_null(""));
}

static void align_dna_testing(){
    result string_result;
    TEST_INT(STRING_NULL, Pairwise_align_dna("A", "",  &string_result));
    TEST_INT(RUN_OK, Pairwise_align_dna("AACC","AATACC",  &string_result));
    std::cout <<string_result.final_result;
    TEST_STRING("AATACC", string_result.final_result);
}

static void testing(){
    align_dna_testing();
}

int main(){
    testing();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}

