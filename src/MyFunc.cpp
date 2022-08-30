/** @file */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <cmath>
#include <inttypes.h>

#include "Macros.h"
#include "MyString.h"

/**
*   @brief Determines if number less than zero, more than zero or equal to zero
*
*   @param num [in] num - number given to determine
*
*   @return num < 0: -1 | num == 0: 0 | num > 0: 1
*/

int Signum(const double num)
{
    if (num < 0)
        return -1;

    if (num > 0)
        return 1;

    return 0;
}

/**
*   @brief Determines if double number is finite: normal, subnormal or zero, not infinite or NaN
*
*   @param num [in] num - double number
*
*   @return is finite ? 1 : 0
*/

int IsFinite(const double num)
{
    uint64_t int_num = *(uint64_t*)&num;

    uint64_t         infinite_mask = (uint64_t) 0x7ff << 52;
    uint64_t check = infinite_mask & int_num;

    return check != infinite_mask;
}

/**
*   @brief Swaps two pointers to the string
*
*   @param a [in] [out] a - pointer to the first byte of first string
*   @param b [in] [out] b - pointer to the first byte of second string
*
*   @return nothing
*/

void StringSwap(char** const a, char** const b)
{
    MyAssert(a != NULL);
    MyAssert(b != NULL);

    char* c = *a;
    *a = *b;
    *b = c;
}

/**
*   @brief Swaps values of two double numbers
*
*   @param a [in] [out] a - pointer to the first  double number
*   @param b [in] [out] b - pointer to the second double number
*
*   @return nothing
*/

void DoubleSwap(double* const a, double* const b)
{
    MyAssert(a != NULL);
    MyAssert(b != NULL);

    double c = *a;
    *a = *b;
    *b = c;
}

/**
*   @brief Compare two double numbers
*
*   @param a [in] a - first number
*   @param b [in] b - second number
*
*   @return (a belong to neighborhood [b - delta; b + delta]) ? 1 : 0
*/

int IsEqual(const double a, const double b)
{
    MyAssert(IsFinite(a));
    MyAssert(IsFinite(b));

    const double delta = 0.00001;

    return fabs(a - b) <= delta;
}

/**
*   @brief Skips all input up to next '\n'
*
*   @param stream [in] stream - input stream
*
*   @return nothing
*/

void clear_input_buff(FILE* const stream)
{
    MyAssert(stream != NULL);

    char ClearingTemp ='#';
    while ((ClearingTemp = getc(stream)) != '\n' && ClearingTemp != EOF) {
        ;
    }

    if (ClearingTemp == '\n') {
        ungetc(ClearingTemp, stream);
    }
}

/**
*   @brief Determines is input stream empty. Stops if a newline character found.
*   @brief empty stream does not include any symbols besides spaces
*
*   @param stream [in] stream - input stream
*
*   @return is empty ? 1 : 0
*/

int is_empty_input_buff(FILE* const stream)
{

    MyAssert(stream != NULL);

    char IsEmptyTemp = ' ';
    while ((IsEmptyTemp = getc(stream)) == ' ' || IsEmptyTemp == '\t') {
        ;
    }

    ungetc(IsEmptyTemp, stream);

    return IsEmptyTemp == '\n' || IsEmptyTemp == EOF;
}

/**
*   @brief Makes quick sort of pointers to the null-terminated byte strings array "data".
*   @brief Sorts lexicography.
*
*   @param  data [in] [out] data - array to sort
*   @param  left [in]       left - begin of sorting part
*   @param right [in]      right -   end of sorting part
*
*   @return nothing
*/

void string_quick_sort(char **data, int left, int right)
{
    MyAssert(data != NULL);

    if (left >= right)
        return;

    StringSwap(&data[left], &data[(left + right) / 2]);

    int cut = left;
    for (int i = left + 1; i <= right; ++i) {

        if (MyStrcmp(data[i], data[left]) <= 0) {

            StringSwap(&data[++cut], &data[i]);
        }
    }

    StringSwap(&data[cut], &data[left]);

    string_quick_sort(data, left, cut - 1);
    string_quick_sort(data, cut + 1, right);
}
