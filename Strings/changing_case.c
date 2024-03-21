#include<stdio.h>

int main()
{
        char *s = (char *)malloc(sizeof(char));

    //scanf("%s",s);
    gets(s);
    int i;
    for(i=0; s[i]!='\0';i++)    
    {
        if(s[i]>= 65 && s[i]<=90)       // A = 65 , Z = 90 
        {
            s[i]+=32;
        }
        else if(s[i]>='a' && s[i]<='z')
        {
            s[i]-=32;
        }
    }
    printf("%s", s);
    printf("\n");
    return 0;
}