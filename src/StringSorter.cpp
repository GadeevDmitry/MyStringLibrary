/** @file */

#include <stdio.h>
#include <stdlib.h>

#include "Macros.h"
#include "MyString.h"
#include "MyFunc.h"
#include "StringSorter.h"

/**
*   @brief Reads strings from "stream" and allocates memory for them
*   @brief Makes array of pointers to these strings
*
*   @param stream [in] stream - file to read from
*   @param   Size [out]  Size - size of obtained array
*
*   @return pointer to the first element of array
*/

char **get_pointer_array(FILE* const stream, int* const Size)
{
    *Size = 1000; //begin Data Size

    char **DataStore = (char **) calloc(*Size, sizeof(char *));

    MyAssert(stream != NULL);
    MyAssert(DataStore != NULL);

    for (int i = 0; i <= *Size; ++i) {

        char *NowString = MyGetline(stream, '\n');

        if (NowString == NULL) {

            *Size = i;
            return (char **) realloc(DataStore, *Size * sizeof(char *));
        }
        if (i == *Size) {
            *Size *= 2;
            DataStore = (char **) realloc(DataStore, *Size * sizeof(char *));

            MyAssert(DataStore != NULL);
        }

        DataStore[i] = NowString;
    }

    return DataStore;
}

void SorterMain()
{
    FILE* Text = fopen("Text.txt", "r");

    int Size = 0;
    char ** DataStore = get_pointer_array(Text, &Size);

    fclose(Text);

    QuickSort(DataStore, sizeof(char *), 0, Size - 1, (int (*)(void*, void*)) only_letter_string_cmp);

    FILE* SortedText = fopen("SortedText.txt", "w");

    for (int i = 0; i < Size; ++i) {
        if (at_least_one_letter(DataStore[i])) {

            MyPuts(DataStore[i], SortedText);
        }
        free(DataStore[i]);
    }

    fclose(SortedText);
}
