#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkAnagram(char *s, char *p)
{
  int h[26], i;

  for (i = 0; i < 26; i++)
  {
    h[i] = 0;
  }
  for (i = 0; s[i] != '\0'; i++)
  {
    h[s[i] - 97] += 1;
  }

  for (i = 0; p[i] != '\0'; i++)
  {
    h[p[i] - 97] -= 1;
    if (h[p[i] - 97] < 0)
    {
      return 0;
      break;
    }
  }
  if (s[i] || p[i])
    return 0;
  else if (p[i] == '\0')
    return 1;
  ;
}

int main() // ans -  medical,decimal -- same letters new words
{
  char *s = (char *)malloc(sizeof(char)), *p = (char *)malloc(sizeof(char));
  gets(s);
  gets(p);
  // char s[] = "medical";
  // char p[] = "decimal";

  if (checkAnagram(s, p) == 1)
    printf("The two strings are anagram of each other");
  else
    printf("The two strings are not anagram of each other");
}
