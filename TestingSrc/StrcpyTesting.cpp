/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/Macros.h"
#include "../src/MyString.h"
#include "../src/MyFunc.h"

#define MAX_STRING_SIZE 1000

void my_strcpy_failed_test_output(int TestNum,
                                  char* const to, char* const from)
{
    printf("\nERROR ON TEST NUMBER %d\n"
           "FUNCTION: STRCPY\n"
           "EXPECTED: %s\n"
           "YOUR ANS: %s\n", TestNum, from, to);
}

void my_strcpy_check(int TestNum, int* const fails,
                     char* const to, char* const from)
{
    MyStrcpy(to, from);

    if (strcmp(to, from)) {

        ++*fails;
        my_strcpy_failed_test_output(TestNum, to, from);
    }
    else {
        printf("\nTest number %d ok\n", TestNum);
    }
}

void strcpy_read_tests()
{
    printf("\nSTRCPY TESTING\n");

    FILE *TestsFile = fopen("tests/my_strcpy_tests.txt", "r");

    int TestNum = 0, fails = 0;

    while (!is_empty_input_buff(TestsFile)) {

        ++TestNum;

        char from[MAX_STRING_SIZE] = "";
        char   to[MAX_STRING_SIZE] = "";

        fscanf(TestsFile, "%s %s", to, from);

        my_strcpy_check(TestNum, &fails, to, from);

        clear_input_buff(TestsFile);
        getc(TestsFile);
    }

    fclose(TestsFile);
    printf("\n Total strcpy tests: %d\n"
           "Failed strcpy tests: %d\n", TestNum, fails);
}

