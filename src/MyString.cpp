/** @file */

#include <stdio.h>
#include <stdlib.h>

#include "Macros.h"

/**
*   @brief Prints the null-terminated byte string in stdout ending with character '\n'
*
*   @param s [in] s - pointer to the first byte of string to print
*
*   @return EOF in case of error and non-negative value else
*/

int MyPuts(const char *s)
{
    MyAssert(s != NULL);

    while (*s) {

        if (putchar(*s++) == EOF) {
            return EOF;
        }
    }

    putchar('\n');

    return 1;
}

/**
*   @brief Finds first entry of character 'c' in null-terminated byte string s
*
*   @param s [in] s - pointer on the first byte of string
*   @param c [in] c - character to find
*
*   @return pointer to the founded character or NULL if it can not be found
*/

char *MyStrchr(const char *s, int c)
{
    MyAssert(s != NULL);

    while (*s && *s != c) {
        ++s;
    }

    return *s == c ? (char*)s : NULL;
}

/**
*   @brief Finds the length of null-terminated byte string
*
*   @param s [in] s - pointer to the first byte of byte string
*
*   @return length of string
*/

int MyStrlen(const char *s)
{
    MyAssert(s != NULL);

    int len = 0;
    for (; s[len]; ++len) {
        ;
    }

    return len;
}

/**
*   @brief Copies null-terminated byte string to the character array
*
*   @param   to [out]  to - pointer to the first byte of character array given for copy in
*   @param from [in] from - pointer to the first byte of     byte string given for copy from
*
*   @return pointer to the first byte of string "to"
*/

char *MyStrcpy(char *to, const char *from)
{
    MyAssert(  to != NULL);
    MyAssert(from != NULL);

    MyAssert(from != to);

    char* const begin_to = to;

    while (*from) {
        *to++ = *from++;
    }

    *to = '\0';

    return begin_to;
}

/**
*   @brief Copies not more than "n" first bytes of byte string "from" to the character array "to".
*   @brief Adds null terminator in the end
*
*   @param   to [out]  to - pointer to the first byte of character array given for copy in
*   @param from [in] from - pointer to the first byte of     byte string given for copy from
*   @param    n [in]    n - max number of characters to copy
*
*   @return pointer to the first byte of string "to"
*/

char *MyStrncpy(char *to, const char *from, int n)
{
    MyAssert(  to != NULL);
    MyAssert(from != NULL);

    MyAssert(to != from);

    char* const begin_to = to;

    while (n-- && *from) {
        *to++ = *from++;
    }

    *to = '\0';

    return begin_to;
}

/**
*   @brief Appends the copy of null-terminated string "from" to the end of null-terminated string "to"
*   @brief Result byte string is null-terminated
*
*   @param   to [out]  to - pointer to the first byte of byte string given for append to
*   @param from [in] from - pointer to the first byte of byte string given for   copy from
*
*   @return pointer to the first byte of result string "to"
*/

char *MyStrcat(char *to, const char *from)
{
    MyAssert(  to != NULL);
    MyAssert(from != NULL);

    MyAssert(to != from);

    char* const begin_to = to;

    while (*to) {
        ++to;
    }

    while (*from) {
        *to++ = *from++;
    }

    *to = '\0';

    return begin_to;

}

/**
*   @brief Appends not more than "n" bytes of byte string "from" to the end of null-terminated string "to"
*   @brief Result byte string is null-terminated
*
*   @param   to [out]  to - pointer to the first byte of byte string given for append to
*   @param from [in] from - pointer to the first byte of byte string given for   copy from
*   @param    n [in]    n - max number of character to copy
*
*   @return pointer to the first byte of result string "to"
*/

char *MyStrncat(char *to, const char *from, int n)
{
    MyAssert(  to != NULL);
    MyAssert(from != NULL);

    MyAssert(to != from);

    char* const begin_to = to;

    while (*to) {
        ++to;
    }

    while (n-- && *from) {
        *to++ = *from++;
    }

    *to = '\0';

    return begin_to;
}

/**
*   @brief Reads not more than "n - 1" character from "stream". Stores input in character array "s".
*   @brief Stops reading if a newline character is found or stream is empty.
*   @brief Adds the newline character in the array;
*
*   @param      s [out]     s - pointer to the first byte of character array given for write in
*   @param      n [in]      n - max number of character to append
*   @param stream [in] stream - pointer to the stream given for read from
*
*   @return pointer to the first byte of result null-terminated byte string
*/

char *MyFgets(char *s, int n, FILE* const stream)
{
    MyAssert(     s != NULL);
    MyAssert(stream != NULL);

    char c = '#';
    char* const begin_s = s;

    if ((c = getc(stream)) == EOF) {
        return NULL;
    }

    ungetc(c, stream);

    while (--n && (c = getc(stream)) != EOF && c != '\n') {
        *s++ = c;
    }

    if (n && c == '\n') {
        *s++ = '\n';
    }

    *s = '\0';

    return begin_s;
}

/**
*   @brief Allocates memory for null-terminated byte string which is a duplicate of another string given
*
*   @param from [in] from - pointer to the null-terminated byte string to duplicate
*
*   @return pointer to the duplicate byte string or NULL in case of error
*/

char *MyStrdup(const char *original)
{
    MyAssert(original != NULL);

    char *duplicate = (char*) calloc(MyStrlen(original) + 1, sizeof(char));

    if (duplicate == NULL) {
        return NULL;
    }

    MyStrcpy(duplicate, original);

    return duplicate;
}

/**
*   @brief Compares two null-terminated byte strings lexicographically
*
*   @param s1 [in] s1 - pointer to the first byte of  first string to compare
*   @param s2 [in] s2 - pointer to the first byte of second string to compare
*
*   @return negative value if first string    lexicographically less than second string
*   @return positive value if first string is lexicographically more than second string
*   @return     zero value if first string is lexicographically equal  to second string
*/

int MyStrcmp(const char *s1, const char *s2)
{
    MyAssert(s1 != NULL);
    MyAssert(s2 != NULL);

    while (*s1 || *s2) {

        int del = (*s1++ - *s2++);

        if (del) {
            return del;
        }
    }

    return 0;
}

