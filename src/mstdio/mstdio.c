#include "mstdio.h"

int mputs(const char *str)
{
    if (!str) return EOF;

    char *ret = str;

    while (*str)
    {
        if (write(STDOUT_FILENO, str, 1)  == -1) return EOF;
        str++;
    }

    if (write(STDOUT_FILENO, "\n", 1) == -1) return EOF;

    return str - ret;
}

char *mfgets(char *str, int count, const FILE const* stream)
{
    if (!str || count < 0 || !stream) return NULL;
    if (count == 0) return str;

    char *ret = str;
    char ch   = '\0';
    
    while (--count > 0)
    {
        if ((ch = getc(stream)) == EOF)
        {
            if (str == ret) return NULL;
            break;
        }
        *str++ = ch;
        if (ch == '\n') break;
    }

    *str = '\0';

    return ret;
}

ssize_t mgetline(char **lineptr, size_t *n, const FILE const* stream)
{
    if (!lineptr || !n || !stream) return -1;

    if (!*lineptr || *n == 0)
    {
        *n = 128;
        *lineptr = calloc(*n, sizeof(char));
        if (!*lineptr) return -1;
    }

    int pos = 0;
    int c   = 0;
    while ((c = getc(stream)) != EOF)
    {
        if (pos + 1 >= *n)
        {
            size_t new_size = *n * 2;
            char *new_ptr   = (char *)realloc(*lineptr, new_size);
            if (!new_ptr) return -1;
            *lineptr = new_ptr;
            *n       = new_size;
        }
        (*lineptr)[pos++] = (char)c;
        if (c == '\n') break;
    }

    if (pos == 0 && c == EOF) return -1;
    (*lineptr)[pos] = '\0';
    return pos;
}
