#include <stdio.h>

int main()
{
    char s[20];
    gets(s);
    int i, vcount=0, ccount=0, words=1, letters=0;
    for (i = 0; s[i] != '\0'; i++)
    {
        // vowels

        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            vcount++;
        }

        // consonant

        else if (s[i] >= 65 && s[i] <= 90 || s[i] >= 'a' && s[i] <= 'z')
        {
            ccount++;
        }

        // words

        if(s[i]==' ' && s[i-1]!=' ')
            words++;

        if(s[i]!=' ')
            letters++;

    }
    printf("vowels: %d, consonant: %d, words: %d, letters: %d\n", vcount, ccount, words, letters);





    return 0;
}