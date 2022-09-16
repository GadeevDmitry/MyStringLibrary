#ifndef MACROS_H
#define MACROS_H

#include <stdlib.h>

#define MyAssert(condition)                                                                       \
        if (!(condition)) {                                                                       \
            printf("\n  ERROR: %s\n"                                                              \
                   "FILE NAME: %s\n"                                                              \
                   " FUNCTION: %s\n"                                                              \
                        "LINE: %d\n", #condition, __FILE__, __PRETTY_FUNCTION__, __LINE__);       \
            abort();                                                                              \
        }

struct word
{
    char *Begin;
    int Len;
};

struct text
{
    char *Data;
    int DataSize;

    struct word *Strings;
    int StringsNumber;
};

#endif //MACROS
