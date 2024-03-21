#include <stdio.h>

int palindrome(char s[])
{
    int i, j;
    for (j = 0; s[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return 0;
        else
            return 1;
    }
}

int main()
{
    char s[20];
    gets(s);
    
    printf("%d",palindrome(s));
    printf("\n");
    return 0;
}