#include "mstdlib.h"

int matoi (const char *str)
{
    if (!str) return 0;
    
    int sign   = 1;
    int result = 0;
    
    while (*str == ' ') str++;
    
    if (*str == '-') { sign = -1; str++; }
    if (*str == '+')   str++;
    
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    
    result *= sign;
    
    return result;
}
