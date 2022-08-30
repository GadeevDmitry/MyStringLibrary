/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/Macros.h"
#include "../src/MyString.h"
#include "../src/MyFunc.h"

#define MAX_STRING_SIZE 1000

void my_strcmp_failed_test_output(int TestNum,
                                  const int StrcmpAns, const int RightAns)
{
    printf("\nERROR ON TEST NUMBER %d\n"
           "FUNCTION: STRCMP\n"
           "EXPECTED: %d\n"
           "YOUR ANS: %d\n", TestNum, RightAns, StrcmpAns);
}

void my_strcmp_check(int TestNum, int* const fails,
                     char* const s1, char* const s2)
{
    int  RightAns =   strcmp(s1, s2);
    int StrcmpAns = MyStrcmp(s1, s2);

    int StrcmpSign = Signum(StrcmpAns);
    int  RightSign = Signum( RightAns);

    if (RightSign != StrcmpSign) {

        ++*fails;
        my_strcmp_failed_test_output(TestNum, StrcmpSign, RightSign);
    }
    else {
        printf("\nTest number %d ok\n", TestNum);
    }
}

void strcmp_read_tests()
{
    printf("\nSTRCMP TESTING\n");

    FILE *TestsFile = fopen("tests/my_strcmp_tests.txt", "r");
    int TestNum = 0, fails = 0;

    while (!is_empty_input_buff(TestsFile)) {

        ++TestNum;

        char s1[MAX_STRING_SIZE] = "";
        char s2[MAX_STRING_SIZE] = "";

        fscanf(TestsFile, "%s %s", s1, s2);

        my_strcmp_check(TestNum, &fails, s1, s2);

        clear_input_buff(TestsFile);
        getc(TestsFile);
    }

    fclose(TestsFile);
    printf("\n Total strcmp tests: %d\n"
           "Failed strcmp tests: %d\n", TestNum, fails);
}

