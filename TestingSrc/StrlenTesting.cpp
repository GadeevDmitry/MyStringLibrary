/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/Macros.h"
#include "../src/MyString.h"
#include "../src/MyFunc.h"

#define MAX_STRING_SIZE 1000

void my_strlen_failed_test_output(int TestNum,
                                  const int StrlenAns, const int RightAns)
{
    printf("\nERROR ON TEST NUMBER %d\n"
           "FUNCTION: STRLEN\n"
           "EXPECTED: %s\n"
           "YOUR ANS: %s\n", TestNum, RightAns, RightAns);
}

void my_strlen_check(int TestNum, int* const fails,
                     char* const s)
{
    int  RightAns =   strlen(s);
    int StrlenAns = MyStrlen(s);

    if (RightAns != StrlenAns) {

        ++*fails;
        my_strlen_failed_test_output(TestNum, StrlenAns, RightAns);
    }
    else {
        printf("\nTest number %d ok\n", TestNum);
    }
}

void strlen_read_tests()
{
    printf("\nSTRLEN TESTING\n");

    FILE *TestsFile = fopen("tests/my_strlen_tests.txt", "r");
    int TestNum = 0, fails = 0;

    while (!is_empty_input_buff(TestsFile)) {

        ++TestNum;

        char s[MAX_STRING_SIZE];

        fscanf(TestsFile, "%s", s);

        my_strlen_check(TestNum, &fails, s);

        clear_input_buff(TestsFile);
        getc(TestsFile);
    }

    fclose(TestsFile);
    printf("\n Total strlen tests: %d\n"
           "Failed strlen tests: %d\n", TestNum, fails);
}
