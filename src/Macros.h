#ifndef MACROS_H
#define MACROS_H

#define MyAssert(condition)                                                                       \
        if (!(condition)) {                                                                       \
            printf("\nERROR: %s\n"                                                                \
                   "FILE NAME: %s\n"                                                              \
                   " FUNCTION: %s\n"                                                              \
                   "     LINE: %d\n", #condition, __FILE__, __PRETTY_FUNCTION__, __LINE__);       \
                   abort();                                                                       \
        }

#endif
