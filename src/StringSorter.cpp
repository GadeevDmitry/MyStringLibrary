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

#include "../TestingSrc/SorterTesting.h"

void SorterMain()
{

    struct text DataStore = {NULL, 0, NULL, 0};

    DataStore = GetData("Text.txt");

    /* printf("DataStore:\n"
           "DataStore.DataSize = %d\n"
           "DataStore.StringsNumber = %d\n\n",
           DataStore.DataSize, DataStore.StringsNumber);

    for (int i = 0; i < DataStore.StringsNumber; ++i) {

        printf("DataStore.Strings = %p\n"
               "DataStore.Strings[%d].Begin = %p\n"
               "DataStore.Strings[%d].Len   = %p\n\n",
               DataStore.Strings, i, DataStore.Strings[i].Begin, i, DataStore.Strings[i].Len);
    } */

    FILE *SortedText = fopen("SortedText.txt", "w");
    MyAssert(SortedText != NULL);

    fprintf(SortedText, "\n\n___________________LEXICOGRAPHY SORT___________________\n\n");

    QuickSort(DataStore.Strings, sizeof(struct word), 0, DataStore.StringsNumber - 2, only_letter_string_cmp);

    // printf("\nSTART ARR_OUTPUT AFTER NORMAL SORTING\n");

    ArrOutput(DataStore.Strings, SortedText);

    // printf("\nFINISH ARR_OUTPUT AFTER NORMAL SORTING\n");

    fprintf(SortedText, "\n\n______________BACKWARDS LEXICOGRAPHY SORT______________\n\n");

    QuickSort(DataStore.Strings, sizeof(struct word), 0, DataStore.StringsNumber - 2, back_only_letter_string_cmp);

    // printf("\nSTART ARR_OUTPUT AFTER BACKWARDS SORTING\n");

    ArrOutput(DataStore.Strings, SortedText);

    // printf("\nFINISH ARR_OUTPUT AFTER BACWARDS SORTING\n");

    fprintf(SortedText, "\n\n________________________ORIGINAL________________________\n\n");

    // printf("\nSTART ORIGINAL OUTPUT\n");

    TextOutput(DataStore.Data, DataStore.DataSize, SortedText);

    // printf("\nFINISH ORIGINAL OUTPUT\n");

    free(DataStore.Data);
    free(DataStore.Strings);
    fclose(SortedText);
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

struct text GetData(const char *name)
{
    MyAssert(name != NULL);

    struct text Store = {NULL, 0, NULL, 2};

    Store.Data = read_file(name, &Store.DataSize);

    // printf("Store.DataSize = %d\n", Store.DataSize);

    // printf("AFTER DEFENDING: Store.StringsNumber = %d\n", Store.StringsNumber);

    Store.StringsNumber += replace('\n', '\0', Store.Data, Store.DataSize);

    // printf("AFTER FIRST REPLACE:  Store.StringsNumber = %d\n", Store.StringsNumber);

    Store.StringsNumber += replace('\r', '\0', Store.Data, Store.DataSize);

    // printf("AFTER SECOND REPLACE: Store.StringsNumber = %d\n", Store.StringsNumber);

    Store.Strings = (word *) calloc(Store.StringsNumber, sizeof(word));
    MyAssert(Store.Strings != NULL);

    // printf("AFTER REPLACES:      Store.DataSize = %d\n", Store.DataSize);
    // printf("AFTER REPLSCES: Store.StringsNumber = %d\n", Store.StringsNumber);

    fill_pointer_array(Store.Data, Store.DataSize + 1, Store.Strings);

    /* printf("Store:\n"
           "Store.DataSize = %d\n"
           "Store.StringsNumber = %d\n\n",
           Store.DataSize, Store.StringsNumber);

    for (int i = 0; i < Store.StringsNumber; ++i) {

        printf("Store.Strings[%d].Begin = %p\n"
               "Store.Strings[%d].Len   = %p\n\n",
               i, Store.Strings[i].Begin, i, Store.Strings[i].Len);
    } */

    return Store;
}

/**
*   @brief Read all data from the file "name" in char *Text once using fread(char *, size_t, int, FILE *)
*   @brief Calls get_file_size(const char *name, FILE *) to found out the size of file
*
*   @param     name [in]      name - name of the file
*   @param TextSize [out] TextSize - pointer to the size of text
*
*   @return pointer to the first byte of text
*/

char *read_file(const char *name, int* const TextSize)
{
    MyAssert(name != NULL);

    *TextSize = get_file_size(name);
    MyAssert(*TextSize != 0);

    FILE *stream = fopen(name, "rb");
    MyAssert(stream != NULL);

    char *Text = (char *) calloc(*TextSize + 1, sizeof(char));
    MyAssert(Text != NULL);

    fread(Text, sizeof(char), *TextSize, stream);
    Text[*TextSize] = '\0';

    fclose(stream);

    return Text;
}

/**
*   @brief Finds it's size(in bytes)
*
*   @param name [in] name - name of the file
*
*   @return size of file
*
*   @note does not close the file
*/

int get_file_size(const char *name)
{
    //printf("\nget_file_size\n");

    MyAssert(name != NULL);

    //printf("FileName = \"%s\"\n", name);
    //printf("\n stream = %p\n", *stream);

    struct stat BuffSize = {0};

    int StatRet = stat(name, &BuffSize);

    //printf("StatRet = %d\n", StatRet);

    if (StatRet == -1) {
        return -1;
    }

    //printf("FileSize = %d\n", BuffSize.st_size);

    return BuffSize.st_size;
}

/**
*   @brief Divides the "Text" on strings. The separator character is null.
*   @brief Puts the address of each string in "Arr".
*
*   @param     Text [in]     Text - pointer to the first byte of the first of byte strings
*   @param TextSize [in] TextSize - number of characters in "Text"
*   @param      Arr [out]     Arr - array of pointers to the struct word
*
*   @return nothing
*/

void fill_pointer_array(char *Text, const int TextSize, struct word *Arr)
{
    MyAssert(Arr  != NULL);
    MyAssert(Text != NULL);

    int arr_pos = 0;
    Arr[arr_pos].Begin = Text;

    for (int current_pos = 0; current_pos < TextSize; ++current_pos) {

        if (Text[current_pos] == '\0') {

            Arr[arr_pos].Len = (Text + current_pos + 1) - Arr[arr_pos++].Begin;

            if (current_pos != TextSize - 1) {

                Arr[arr_pos].Begin = Text + (current_pos + 1);
            }
        }
    }
}

/**
*   @brief Print null-terminated byte strings in the "stream" using array of pointers to the struct word
*   @brief Struct word include pointers to the null-terminated byte strings
*
*   @param    Arr [in]    Arr - pointer to the first element of struct word array.
*   @param stream [in] stream - output stream
*
*   @return nothing
*
*   @note last element of the array "Arr" is the pointer to the NULL. It is a signal to stop writing
*/

void ArrOutput(struct word *Arr, FILE* const stream)
{
    MyAssert(   Arr != NULL);
    MyAssert(stream != NULL);

    while (Arr->Begin) {

        if (at_least_one_NonVoid_char(Arr->Begin)) {

            MyPuts(Arr->Begin, stream);
        }
        Arr++;
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
    MyAssert(  Text != NULL);
    MyAssert(stream != NULL);

    for (int i = 0; i < TextSize; ++i) {

        if (!Text[i]) {

            putc('\n', stream);
            ++i;
        }
        else {

            putc(Text[i], stream);
        }
    }
}
