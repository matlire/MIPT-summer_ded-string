#include "mstring.h"

int mstrcmp(const char *lhs, const char *rhs)
{
    while (*lhs && *lhs == *rhs)
    {
        lhs++;
        rhs++;
    }

    return *(unsigned char *)lhs - *(unsigned char *)rhs;
}

char *mstrchr(const char *str, const int ch)
{
    while (*str)
    {
        if (*str == ch) return str;
        str++;
    }

    if (ch == '\0') return str;

    return NULL;
}

size_t mstrlen(const char const* str)
{
    size_t l = 0;
    while (str[l]) l++; 

    return l;
}

char *mstrcpy(char *dest, const char *src)
{
    char *ret = dest;
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';

    return ret;
}

char *mstrncpy(char *dest, const char *src, size_t count)
{
    char *ret = dest;
    while (*src && count > 0)
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
    if (!dest || !src) return NULL;

    char *ret = dest;
    
    while (*dest) dest++;

    while (*src)
    {
        *dest++ = *src++;
    }

    *dest = '\0';

    return ret;
}

char *mstrncat(char *dest, const char *src, size_t count)
{
    if (!dest || !src || !count || count > mstrlen(src)) return NULL;

    char *ret = dest;
    
    while (*dest) dest++;

    while (*src && count > 0)
    {
        *dest++ = *src++;
        count--;
    }

    *dest = '\0';

    return ret;
}

char *mstrdup(const char *str1)
{
    if (!str1) return NULL;

    char *ptr = (char *)calloc(mstrlen(str1) + 1, sizeof(char));
    if (!ptr) return NULL;

    char *ret = ptr;
    mstrncpy(ptr, str1, mstrlen(str1) + 1);

    return ret;
}

char *mstrstr_base(const char *str, const char *substr)
{
    if (!str || !substr || mstrlen(str) < mstrlen(substr)) return NULL;
    if (!(*substr)) return str;

    for (size_t i = 0; i < mstrlen(str); i++)
    {
        if (str[i] == substr[0])
        {
            size_t saved = i;
            size_t exp   = mstrlen(substr);
            while (str[i] == substr[i - saved] && str[i] && substr[i - saved]) i++;
            if (i - saved == exp) return (char *)str[saved];
            i = saved + 1;
        }
    }

    return NULL;
}
