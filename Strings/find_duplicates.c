#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
int main()
{
    char *s = (char *)malloc(sizeof(char));
    int count;
    gets(s);
    printf("Duplicate characters in a given string: \n");
    // Counts each character present in the string
    for (int i = 0; i < strlen(s); i++)
    {
        count = 1;
        for (int j = i + 1; j < strlen(s); j++)
        {
            if (s[i] == s[j] && s[i] != ' ')
            {
                count++;
                // Set string[j] to 0 to avoid printing visited character
                s[j] = '0';
            }
        }
        // A character is considered as duplicate if count is greater than 1
        if (count > 1 && s[i] != '0')
            printf("%c, %d times\n", s[i],count);
    }
}
*/
/*
int main()
{
    char B[20];
    int H[26];
    gets(B);
    for (int i = 0; i < 26; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 97] += 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            printf("%c, %d times\n", i+97,H[i]);
        }
    }
    return 0;
}
*/

int main()
{
    char *s = (char *)malloc(sizeof(char));
    gets(s);
    //char s[]="finding";
    long int h=0;
    int x = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        x = 1;
        x = x << s[i] - 97;
        if ((x & h) > 0)
            printf("%c is duplicate\n", s[i]);
        else
            h = h | x;
    }
}
