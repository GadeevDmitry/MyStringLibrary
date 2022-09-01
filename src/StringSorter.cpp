/** @file */

#include <stdio.h>
#include <stdlib.h>

#include "Macros.h"
#include "MyString.h"
#include "MyFunc.h"

char **get_pointer_array(FILE* const stream, int* const Size)
{
    *Size = 1000;

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

    string_quick_sort(DataStore, 0, Size - 1);

    FILE* SortedText = fopen("SortedText.txt", "w");

    for (int i = 0; i < Size; ++i)
        MyPuts(DataStore[i], SortedText);

    fclose(SortedText);
}
