#ifndef MSTDIO_H
#define MSTDIO_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int     mputs  (const char *str);
char   *mfgets (char *str, int count, FILE *stream);
ssize_t mgetline(char **lineptr, size_t *n, FILE *stream);

#endif
