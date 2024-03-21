#include <stdio.h>

int valid(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)  // not allow special char
    {
        if (!(s[i] >= 65 && s[i] <= 90) && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 48 && s[i] <= 57))
            return 0;
    }
    return 1;
}

int main()
{
    char s[10];
    gets(s);
    if (valid(s))
        printf("valid\n");
    else
        printf("not valid\n");
    return 0;
}