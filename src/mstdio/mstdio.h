#ifndef MSTDIO_H
#define MSTDIO_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int     mputs   (const char *str);
char   *mfgets  (char *str, int count, const FILE *const stream);
ssize_t mgetline(char **lineptr, size_t *n, const FILE *const stream);

#endif
