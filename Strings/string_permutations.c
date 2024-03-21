#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// method 1

/*
void perm(char *s, int k)
{
    static int a[10]={0};
    static char res[10];
    int i;

    if (s[k] == '\0')
    {
        res[k]='\0';
        printf("%s", res);
        printf("\n");
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (a[i] == 0)
            {
                res[k] = s[i];
                a[i] = 1;
                perm(s, k + 1);
                a[i] = 0;
            }
        }
    }
}
*/

// method 2

void swap(char *s, char *p)
{
    int t = *s;
    *s = *p;
    *p = t;
}

void permutation(char *s, int l, int h)
{
    int i;
    if (l == h)
    {
        printf("%s", s);
        printf("\n");
    }
    else
    {
        for (int i = l; i <= h; i++)
        {
            swap(&s[l], &s[i]);
            permutation(s, l + 1, h);
            swap(&s[l], &s[i]);
        }
    }
}

int main()
{
    // char s[] = "abc";
    char *s = (char *)malloc(sizeof(char));
    gets(s);
    int l = 0, h = strlen(s) - 1;
    permutation(s, l, h);
}
