#include "mstring/mstring.h"
#include "mstdio/mstdio.h"
#include "mstdlib/mstdlib.h"

int main()
{
    char str[] = "Hello World!";
    
    mputs(str);
    mputs(mstrchr(str, 'o'));
    
    printf("%ld\n", mstrlen(str));
    
    char str1[mstrlen(str) + 1] = {  };
    mstrcpy(str1, str);
    str[0] = 'M';
    printf("Original: %s; Copied: %s\n", str, str1);
   
    char str2[mstrlen(str) + 1] = {  };
    mstrncpy(str2, str, 5);
    str[0] = 'E';
    printf("Original: %s; Copied: %s\n", str, str2);

    char str3[mstrlen(str1) + mstrlen(str2) + 1] = {  };
    mstrncpy(str3, str2, 5);
    mstrcat(str3, str1);
    str[0] = 'O';
    printf("Original: %s; Copied: %s\n", str, str3);

    char str4[mstrlen(str1) + mstrlen(str3) + 1] = {  };
    mstrncpy(str4, str3, 7);
    mstrncat(str4, str1, 9);
    str[0] = 'W';
    printf("Original: %s; Copied: %s\n", str, str4);
    
    return 0;
}
