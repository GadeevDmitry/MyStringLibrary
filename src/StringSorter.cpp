/** @file */

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <ctype.h>

#include "Macros.h"
#include "MyString.h"
#include "MyFunc.h"
#include "StringSorter.h"

/**
*   @brief Divides the "Text" on strings. The separator character is null.
*   @brief Puts the address of each string in "Arr".
*
*   @param    Text [in]    Text - pointer to the first byte of the first of byte strings
*   @param PtrSize [in] PtrSize - number of strings in "Text"
*   @param     Arr [out]    Arr - array of pointers to the strings
*
*   @return nothing
*/

void fill_pointer_array(char *Text, const int PtrSize, char **Arr)
{
    int Num = 0;
    Arr[Num++] = Text;

    while (Num < PtrSize) {

        if (*Text++ == '\0') {
            Arr[Num++] = Text;
        }
    }
}

/**
*   @brief Reads strings from file "name" and allocates memory for them in one piece
*   @brief Makes array of pointers to these strings
*
*   @param   stream [in]    stream - file to read from
*   @param     Size [out]     Size - size of obtained array
*   @param TextSize [out] TextSize - size (in bytes) of input text
*
*   @return pointer to the first element of array
*/

char **get_pointer_array(int* const Size, const char* const name, int* const TextSize)
{
    struct stat BuffSize;

    FILE *stream = fopen(name, "rb");

    MyAssert(stream != NULL);
    MyAssert(stat(name, &BuffSize) != -1);

    int TxtSz = *TextSize = BuffSize.st_size;
    char *Text = (char *) calloc(TxtSz + 2, sizeof(char));

    MyAssert(Text != NULL);

    Text[        0] = '\0';
    Text[TxtSz + 1] = '\0';

    fread(Text + 1, sizeof(char), TxtSz, stream);

    fclose(stream);

    *Size =  replace('\n', '\0', Text + 1, TxtSz);
    *Size += replace('\r', '\0', Text + 1, TxtSz);

    char **PtrArr = (char **) calloc(*Size, sizeof(char *));

    fill_pointer_array(Text, *Size, PtrArr);

    return PtrArr;
}

/**
*   @brief Print null-terminated byte strings in the "stream" using array of pointers to the strings
*
*   @param    Arr [in]    Arr - pointer to the first element of pointers to the strings array
*   @param   Size [in]   Size - number of elements in the array
*   @param stream [in] stream - output stream
*
*   @return nothing
*/

void ArrOutput(char **Arr, const int Size, FILE *stream)
{
    for (int i = 0; i < Size; ++i) {

        if (at_least_one_letter(Arr[i]))
            MyPuts(Arr[i], stream);
    }
}

/**
*   @brief Print all text in the output "stream"
*
*   @param     Text [in]     Text - pointer to the first byte of the first of all strings
*   @param TextSize [in] TextSize - size (in bytes) of text
*   @param   stream [in]   stream - output stream
*
*   @return nothing
*/

void TextOutput(char *Text, int TextSize, FILE* const stream)
{
    char is_last_null = 1;

    for (int i = 0; i < TextSize; ++i) {

        if (isalpha(Text[i]) && is_last_null)
            MyPuts(Text + i, stream);

        is_last_null = Text[i] ? 0 : 1;
    }
}

void SorterMain()
{

    int Size = 0, TextSize = 0;
    char ** DataStore = get_pointer_array(&Size, "Text.txt", &TextSize);
    char *TextBegin = *DataStore;

    FILE *SortedText = fopen("SortedText.txt", "w");

    fprintf(SortedText, "\n\n___________________LEXICOGRAPHY SORT___________________\n\n");

    QuickSort(DataStore, sizeof(char *), 0, Size - 1, only_letter_string_cmp);
    ArrOutput(DataStore, Size, SortedText);

    fprintf(SortedText, "\n\n______________BACKWARDS LEXICOGRAPHY SORT______________\n\n");

    QuickSort(DataStore, sizeof(char *), 0, Size - 1, back_only_letter_string_cmp);
    ArrOutput(DataStore, Size, SortedText);

    fprintf(SortedText, "\n\n________________________ORIGINAL________________________\n\n");

    TextOutput(TextBegin, TextSize, SortedText);

    free(DataStore);
    free(TextBegin);
    fclose(SortedText);
}
