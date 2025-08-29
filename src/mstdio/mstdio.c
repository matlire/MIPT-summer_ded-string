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

char *mfgets(char *str, int count, FILE *stream)
{
    if (!str || count < 0 || stream == NULL) return NULL;

    char *ret = str;
    char ch   = '\0';
    
    while (--count > 0)
    {
        ch = (char)getc(stream);
        if (ch == EOF || ch == '\n') break;
        *str++ = ch;
    }

    *str = '\0';

    return ret;
}

