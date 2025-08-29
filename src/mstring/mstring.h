#ifndef MSTRING_H
#define MSTRING_H

#include <stdio.h>
// puts, strchr, strlen, strcpy, strncpy, strcat, strncat, fgets, strdup, getline

char  *mstrchr(const char *str, int ch);

size_t mstrlen(const char *str);

char *mstrcpy (char *dest, const char *src);
char *mstrncpy(char *dest, const char *src, size_t count);

char *mstrcat (char *dest, const char *src);
char *mstrncat(char *dest, const char *src, size_t count);

#endif
