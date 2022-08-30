#ifndef MY_STRING_H
#define MY_STRING_H

char *MyStrchr(const char *s, int c);
char *MyStrdup(const char *s);
char *MyFgets(char *s, int n, FILE* const stream);

char * MyStrcpy(char *to, const char *from);
char *MyStrncpy(char *to, const char *from, int n);

char * MyStrcat(char *to, const char *from);
char *MyStrncat(char *to, const char *from, int n);

int MyStrlen(const char *s);
int   MyPuts(const char *s);
int MyStrcmp(const char *s1, const char *s2);

#endif
