/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/Macros.h"
#include "../src/MyString.h"
#include "../src/MyFunc.h"

#define MAX_STRING_SIZE 1000

void my_strchr_failed_test_output(const int TestNum, char* const RightPtr,
                                                     char* const StrchrPtr)
{
    printf("\nERROR ON TEST NUMBER %d:\n"
           "FUNCTION: STRCHR\n"
           "EXPECTED: %p\n"
           "YOUR ANS: %p\n", TestNum, RightPtr, StrchrPtr);
}

void my_strchr_check(int TestNum, int* const fails,
                     char* s, const int c)
{
    char  *RightPtr =   strchr(s, c);
    char *StrchrPtr = MyStrchr(s, c);

    if (RightPtr != StrchrPtr) {

        ++*fails;
        my_strchr_failed_test_output(TestNum, RightPtr, StrchrPtr);
    }
    else {
        printf("\nTest number %d ok\n", TestNum);
    }
}

void strchr_read_tests()
{
    printf("\nSTRCHR TESTING\n");

    FILE *TestsFile = fopen("tests/my_strchr_tests.txt", "r");
    int TestNum = 0, fails = 0;

    while (!is_empty_input_buff(TestsFile)) {

        ++TestNum;

        char s[MAX_STRING_SIZE] = "";
        char c = '\0';

        fscanf(TestsFile, "%s %c", s, &c);

        my_strchr_check(TestNum, &fails, s, c);

        clear_input_buff(TestsFile);
        getc(TestsFile);
    }

    fclose(TestsFile);
    printf("\n Total strchr tests: %d\n"
           "Failed strchr tests: %d\n", TestNum, fails);

}
