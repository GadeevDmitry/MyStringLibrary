/** @file */

#include <stdio.h>

#include "flags.h"
#include "MyString.h"
#include "Macros.h"
#include "MyFunc.h"
#include "StringSorter.h"
#include "CommandLine.h"

#include "../TestingSrc/MyStrTesting.h"

/**
*   @brief Finds the number of the program mode by command line argument
*
*   @param s [in] s - pointer to the first byte of null-terminated byte string
*
*   @return number of the mode
*
*   @note return -1 if format of string is wrong
*/

int FindMode(const char *s)
{
    MyAssert(s != NULL);

    int len = MyStrlen(s);

    if (len == 1)
        return -1;

    if (*s++ != '-')
        return -1;

    if (*s != '-') {

        if (len > 2)
            return -1;

        return *s - '0';
    }

    ++s;
    if (len == 3)
        return *s - '0';

    if (len == 4)
        return 10 * (*s - '0') + (*(s + 1) - '0');

    return -1;

}

/**
*   @brief Finds the mode of the program and run it
*
*   @param argc [in] argc - number of command arguments
*   @param argv [in] argv - array  of pointers to the first byte of arguments
*
*   @return nothing
*/

void command_line_query(int argc, const char **argv)
{
    if (argc == 1 || argc > 2) {
        printf("\nYou should give only one switch\n"
               "-0       All Testing []\n"
               "-1  MyStrcpy Testing [\"my_strcpy_tests.txt\"]\n"
               "-2 MyStrncpy Testing [\"my_strncpy_tests.txt\"]\n"
               "-3  MyStrcat Testing [\"my_strcat_tests.txt\"]\n"
               "-4 MyStrncat Testing [\"my_strncat_tests.txt\"]\n"
               "-5  MyStrlen Testing [\"my_strlen_tests.txt\"]\n"
               "-6  MyStrcmp Testing [\"my_strcmp_tests.txt\"]\n"
               "-7  MyStrchr Testing [\"my_strchr_tests.txt\"]\n"
               "-8  MyStrdup Testing [\"my_strdup_tests.txt\"]\n"
               "-9   MyFgets Testing [\"my_fgets_tests.txt\"]\n"
               "--10 Sorting Text\n");
    }
    else {

        int at_least_one_mode = 0;
        int mode = FindMode(argv[1]);

        at_least_one_mode = (mode >= 0 && mode <= 10) ? 1 : 0;

        if (!at_least_one_mode) {
            printf("Print: \"a.exe\" to get manual");
            return;
        }

        switch(mode) {

            case 0:

                 strcpy_read_tests();
                strncpy_read_tests();

                 strcat_read_tests();
                strncat_read_tests();

                strlen_read_tests();
                strcmp_read_tests();
                strchr_read_tests();
                strdup_read_tests();

                fgets_read_tests();

                break;

            case 1:
                strcpy_read_tests();
                break;

            case 2:
                strncpy_read_tests();
                break;

            case 3:
                strcat_read_tests();
                break;

            case 4:
                strncat_read_tests();
                break;

            case 5:
                strlen_read_tests();
                break;

            case 6:
                strcmp_read_tests();
                break;

            case 7:
                strchr_read_tests();
                break;

            case 8:
                strdup_read_tests();
                break;

            case 9:
                fgets_read_tests();
                break;

            case 10:
                SorterMain();
                break;
        }
    }
}
