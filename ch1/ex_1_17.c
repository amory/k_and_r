#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);

/* print longest input line */
int main()
{
  int len; /* current line length */
  char line[MAXLINE];    /* current input line */

  while ((len = mygetline(line, MAXLINE)) > 0)
    if (80 < len-1)
      printf("%s", line);
  return 0;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim)
{
  int c, i;

  for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
