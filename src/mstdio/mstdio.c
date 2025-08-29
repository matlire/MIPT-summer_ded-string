#include "mstdio.h"

int mputs(const char *str)
{
    while (*str)
    {
        if (write(STDOUT_FILENO, str, 1)  == -1) return EOF;
        str++;
    }

    if (write(STDOUT_FILENO, "\n", 1) == -1) return EOF;

    return 0;
}

