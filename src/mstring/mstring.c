#include "mstring.h"

char *mstrchr(const char *str, int ch)
{
    while (*str != '\0')
    {
        if (*str == (char *)ch) return (char *)str;
        str++;
    }

    if (ch == '\0') return (char *)str;

    return NULL;
}

size_t mstrlen(const char *str)
{
    size_t l = 0;
    while (*str != '\0') 
    {
        str++;
        l++;
    }

    return l;
}

char *mstrcpy(char *dest, const char *src)
{
    char *ret = dest;
    while (*src != '\0')
    {
        *dest++ = *src++;
    }
    *dest = '\0';

    return ret;
}

char *mstrncpy(char *dest, const char *src, size_t count)
{
    char *ret = dest;
    while (*src != '\0' && count > 0)
    {
        *dest++ = *src++;
        count--;
    }

    while (count > 0)
    {
        *dest++ = '\0';
        count--;
    }

    return ret;
}

char *mstrcat(char *dest, const char *src)
{
    char *ret = dest;
    
    while (*dest != '\0') *dest++;

    while (*src != '\0')
    {
        *dest++ = *src++;
    }
    *dest = '\0';

    return ret;
}

char *mstrncat(char *dest, const char *src, size_t count)
{
    char *ret = dest;
    
    while (*dest != '\0') *dest++;

    while (*src != '\0' && count > 0)
    {
        *dest++ = *src++;
        count--;
    }

    while (count > 0)
    {
        *dest++ = '\0';
        count--;
    }

    return ret;
}
