#include <stdio.h>
#include <stdlib.h>
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
#define TEST_ALIGN_DNA(expect_status, expect_string, input1, input2)\
    do{\
        result string_result;\
        mystring mystring_one(input1);\
        mystring mystring_two(input2);\
        TEST_INT(expect_status, Pairwise_align_dna(mystring_one, mystring_two, &string_result));\
        TEST_STRING(expect_string, string_result.final_result);\
    }while(0)

static void align_dna_testing(){
    TEST_ALIGN_DNA(RUN_OK, "AATACC", "AACC", "AATACC");
    TEST_ALIGN_DNA(RUN_OK, "AAMTGG", "AAMGG", "AAmTGG");
}

static void testing(){
    align_dna_testing();
}

int main(){
    testing();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}

