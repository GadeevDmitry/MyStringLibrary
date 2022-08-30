/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/Macros.h"
#include "../src/MyString.h"
#include "../src/MyFunc.h"

#define MAX_STRING_SIZE 1000

void my_fgets_failed_test_output(int TestNum,
                                  char* const RightAns, char* const s)
{
    printf("\nERROR ON TEST NUMBER %d\n"
        "FUNCTION: FGETS\n"
        "EXPECTED: %s.\n"
        "YOUR ANS: %s.\n", TestNum, RightAns, s);
}

void my_fgets_check(int TestNum, int* const fails,
                     const int n, FILE* const stream)
{
    char RightAns[MAX_STRING_SIZE] = "";
    char        s[MAX_STRING_SIZE] = "";

    fgets(RightAns, n, stream);

    int Len = strlen(RightAns);

    while (Len--) {
        ungetc(RightAns[Len], stream);
    }

    MyFgets(s, n, stream);

    if (strcmp(s, RightAns)) {

        ++*fails;
        my_fgets_failed_test_output(TestNum, RightAns, s);
    }
    else {
        printf("\nTest number %d ok\n", TestNum);
    }
}

void fgets_read_tests()
{
    printf("\nFGETS TESTING\n");

    FILE *TestsFile = fopen("tests/my_fgets_tests.txt", "r");
    int TestNum = 0, fails = 0;

    while (!is_empty_input_buff(TestsFile)) {

        ++TestNum;

        int n = 0;

        fscanf(TestsFile, "%d", &n);

        my_fgets_check(TestNum, &fails,
                       n, TestsFile);

        clear_input_buff(TestsFile);
        getc(TestsFile);
    }

    fclose(TestsFile);
    printf("\n Total fgets tests: %d\n"
           "Failed fgets tests: %d\n", TestNum, fails);
}
