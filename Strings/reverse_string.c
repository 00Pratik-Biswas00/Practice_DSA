#include<stdio.h>

void reverse(char s[])
{
    int i,j;
    for(j=0; s[j]!='\0';j++)   
    {}
    j=j-1;
    for(i=0; i<j;i++,j--)   
    {
        int t = s[i];
        s[i]=s[j];
        s[j]=t;
    }
}


int main()
{
    char s[20];
    //scanf("%s",s);
    gets(s);
    reverse(s);
    printf("%s",s);
    printf("\n");
    return 0;
}