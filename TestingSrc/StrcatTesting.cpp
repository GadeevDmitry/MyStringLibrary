/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/Macros.h"
#include "../src/MyString.h"
#include "../src/MyFunc.h"

#define MAX_STRING_SIZE 1000

void my_strcat_failed_test_output(int TestNum,
                                  char* const to, char* const RightAns)
{
    printf("\nERROR ON TEST NUMBER %d\n"
        "FUNCTION: STRCAT\n"
        "EXPECTED: %s\n"
        "YOUR ANS: %s\n", TestNum, RightAns, to);
}

void my_strcat_check(int TestNum, int* const fails,
                     char* const to, char* const from)
{
    char RightAns[MAX_STRING_SIZE] = "";

    strcpy(RightAns, to);
    strcat(RightAns, from);

    MyStrcat(to, from);

    if (strcmp(to, RightAns)) {

        ++*fails;
        my_strcat_failed_test_output(TestNum, to, RightAns);
    }
    else {
        printf("\nTest number %d ok\n", TestNum);
    }
}

void strcat_read_tests()
{
    printf("\nSTRCAT TESTING\n");

    FILE *TestsFile = fopen("tests/my_strcat_tests.txt", "r");
    int TestNum = 0, fails = 0;

    while (!is_empty_input_buff(TestsFile)) {

        ++TestNum;

        char from[MAX_STRING_SIZE] = "";
        char   to[MAX_STRING_SIZE] = "";

        fscanf(TestsFile, "%s %s", to, from);

        my_strcat_check(TestNum, &fails, to, from);

        clear_input_buff(TestsFile);
        getc(TestsFile);
    }

    fclose(TestsFile);
    printf("\n Total strcat tests: %d\n"
           "Failed strcat tests: %d\n", TestNum, fails);
}
