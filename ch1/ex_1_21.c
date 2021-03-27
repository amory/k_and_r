#include <stdio.h>

#define TABSIZE 4

int main(void)
{
    int c, pos, space;

    space = pos = 0;
    while ((c = getchar()) != EOF) {

        ++pos;

        if (c == ' ') {
            ++space;

            if (!(pos % TABSIZE)) {
                putchar('\t');
                space = 0;
            }
        }
        else if (c == '\n') {
            pos = 0;
            space = 0;
        }
        else {
            for (; 0 < space; --space)
                putchar(' ');
            putchar(c);
        }
    }
}
