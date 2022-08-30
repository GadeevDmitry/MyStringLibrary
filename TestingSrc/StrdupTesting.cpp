/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/Macros.h"
#include "../src/MyString.h"
#include "../src/MyFunc.h"

#define MAX_STRING_SIZE 1000

void my_strdup_failed_test_output(int TestNum,
                                  char* const s, char* const StrdupAns)
{
    if (StrdupAns == NULL) {
        printf("\nERROR ON TEST NUMBER %d\n"
               "FUNCTION: STRDUP\n"
               "EXPECTED: %s\n"
               "YOUR ANS: NULL\n", TestNum, s);
    }
    else {
        printf("\nERROR ON TEST NUMBER %d\n"
                "EXPECTED: %s\n"
                "YOUR ANS: %s\n", TestNum, s, StrdupAns);
    }
}

void my_strdup_check(int TestNum, int* const fails,
                     char* const s)
{
    char *StrdupAns = MyStrdup(s);

    if (StrdupAns == NULL || strcmp(s, StrdupAns)) {

        ++*fails;
        my_strdup_failed_test_output(TestNum, s, StrdupAns);
    }
    else {
        printf("\nTest number %d ok\n", TestNum);
    }
}

void strdup_read_tests()
{
    printf("\nSTRDUP TESTING\n");

    FILE *TestsFile = fopen("tests/my_strdup_tests.txt", "r");
    int TestNum = 0, fails = 0;

    while (!is_empty_input_buff(TestsFile)) {

        ++TestNum;

        char s[MAX_STRING_SIZE] = "";

        fscanf(TestsFile, "%s", s);

        my_strdup_check(TestNum, &fails, s);

        clear_input_buff(TestsFile);
        getc(TestsFile);
    }

    fclose(TestsFile);
    printf("\n Total strdup tests: %d\n"
           "Failed strdup tests: %d\n", TestNum, fails);
}
