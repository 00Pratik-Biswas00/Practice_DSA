#include <stdio.h>

int main()
{
  char *s = (char *)malloc(sizeof(char));

  // scanf("%s",s);
  gets(s);
  int i;
  for (i = 0; s[i] != '\0'; i++) // you can also use while loop
  {
  }
  printf("Length: %d\n", i);
  return 0;
}