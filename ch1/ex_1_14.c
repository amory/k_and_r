#include <stdio.h>

#define MAXCHARS 256

int main()
{

  int ch[MAXCHARS]; // number of ascii chars
  int c, i, j;

  for (i = 0; i < MAXCHARS; ++i)
    ch[i] = 0;

  while ((c = getchar()) != EOF)
    ++ch[c];

  for (i = 0; i < MAXCHARS; ++i)
    if (0 < ch[i]) {
      if (i == ' ' || i == '\t' || i == '\n')
        continue;
      printf("%c ", i);
      for (j = 0; j < ch[i]; ++j)
        putchar('*');
      putchar('\n');
    }
}
