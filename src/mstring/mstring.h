#ifndef MSTRING_H
#define MSTRING_H

#include <stdio.h>
#include <stdlib.h>

int    mstrcmp(const char *lhs, const char *rhs);

char  *mstrchr(const char *str, int ch);

size_t mstrlen(const char *str);

char *mstrcpy (char *dest, const char *src);
char *mstrncpy(char *dest, const char *src, size_t count);

char *mstrcat (char *dest, const char *src);
char *mstrncat(char *dest, const char *src, size_t count);

char *mstrdup(const char *str1);

#endif
