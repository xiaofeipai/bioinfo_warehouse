#ifndef _PARI_ALIGN_DNA_BIOINFO_H_
#define _PARI_ALIGN_DNA_BIOINFO_H_

typedef enum{PAIR_ALIGN_DNA} run_type;
typedef enum{RUN_OK, STRING_NULL, STRING_INVALID} run_status;
typedef enum{FROM_LEFT, FROM_UP, FROM_DIAGONAL} grade_from;

struct result{
    run_type r;
    const char* final_result;
};

bool if_null(const char* string_one);
int get_string_length(const char* string_one);
int align_letter(char one, char two);
run_status Pairwise_align_dna(const char* string_one, const char * string_two, result* string_result);
#endif