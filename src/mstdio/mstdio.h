#ifndef MSTDIO_H
#define MSTDIO_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int   mputs(const char *str);
char *mfgets(char *str, int count, FILE *stream);

#endif
