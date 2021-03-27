#include <stdio.h>

#define TABSIZE 8

int main(void)
{
    int c, pos, tab;

    pos = 0;
    while ((c = getchar()) != EOF) {

        ++pos;

        if (c == '\t') {
            tab = TABSIZE - (pos-1) % TABSIZE;
            while (0 < tab) {
                putchar(' ');
                ++pos;
                --tab;
            }

        } else if (c == '\n') {
            putchar('\n');
            pos = 0;

        } else
            putchar(c);
    }
    return 0;
}
