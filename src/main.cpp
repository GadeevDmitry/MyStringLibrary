/** @file */

#include <stdio.h>

#include "MyString.h"
#include "../TestingSrc/MyStrTesting.h"
#include "MyFunc.h"

int main(int argc, const char *argv[])
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
               "-9   MyFgets Testing [\"my_fgets_tests.txt\"]\n");
    }

    else if (argc == 2) {

        int IsAll = MyStrcmp(argv[1], "-0") ? 0 : 1;
        int AtLeastOneMode = 0;
        if (IsAll || !MyStrcmp(argv[1], "-1")) {
            strcpy_read_tests();
            AtLeastOneMode = 1;
        }

        if (IsAll || !MyStrcmp(argv[1], "-2")) {
            strncpy_read_tests();
            AtLeastOneMode = 1;
        }

        if (IsAll || !MyStrcmp(argv[1], "-3")) {
            strcat_read_tests();
            AtLeastOneMode = 1;
        }

        if (IsAll || !MyStrcmp(argv[1], "-4")) {
            strncat_read_tests();
            AtLeastOneMode = 1;
        }

        if (IsAll || !MyStrcmp(argv[1], "-5")) {
            strlen_read_tests();
            AtLeastOneMode = 1;
        }

        if (IsAll || !MyStrcmp(argv[1], "-6")) {
            strcmp_read_tests();
            AtLeastOneMode = 1;
        }

        if (IsAll || !MyStrcmp(argv[1], "-7")) {
            strchr_read_tests();
            AtLeastOneMode = 1;
        }

        if (IsAll || !MyStrcmp(argv[1], "-8")) {
            strdup_read_tests();
            AtLeastOneMode = 1;
        }

        if (IsAll || !MyStrcmp(argv[1], "-9")) {
            fgets_read_tests();
            AtLeastOneMode = 1;
        }

        if (!AtLeastOneMode) {
            printf("Print \"a.exe\" to get manual");
        }
    }
}
