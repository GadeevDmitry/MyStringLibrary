/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/Macros.h"
#include "../src/MyString.h"
#include "../src/MyFunc.h"

#define MAX_STRING_SIZE 1000

void my_strncat_failed_test_output(int TestNum,
                                  char* const to, char* const RightAns)
{
    printf("\nERROR ON TEST NUMBER %d\n"
           "FUNCTION: STRNCAT\n"
           "EXPECTED: %s\n"
           "YOUR ANS: %s\n", TestNum, RightAns, to);
}

void my_strncat_check(int TestNum, int* const fails,
                     char* const to, char* const from, const int n)
{
    char RightAns[MAX_STRING_SIZE] = "";

    strcpy(RightAns, to);
    strncat(RightAns, from, n);

    MyStrncat(to, from, n);

    if (strcmp(to, RightAns)) {

        ++*fails;
        my_strncat_failed_test_output(TestNum, to, RightAns);
    }
    else {
        printf("\nTest number %d ok\n", TestNum);
    }
}

void strncat_read_tests()
{
    printf("\nSTRNCAT TESTING\n");

    FILE *TestsFile = fopen("tests/my_strncat_tests.txt", "r");
    int TestNum = 0, fails = 0;

    while (!is_empty_input_buff(TestsFile)) {

        ++TestNum;

        char from[MAX_STRING_SIZE] = "";
        char   to[MAX_STRING_SIZE] = "";

        int n = 0;

        fscanf(TestsFile, "%s %s %d", to, from, &n);

        my_strncat_check(TestNum, &fails, to, from, n);

        clear_input_buff(TestsFile);
        getc(TestsFile);
    }

    fclose(TestsFile);
    printf("\n Total strncat tests: %d\n"
           "Failed strncat tests: %d\n", TestNum, fails);
}
