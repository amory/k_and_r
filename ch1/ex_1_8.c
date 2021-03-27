#include <stdio.h>

int main()
{
    int c, b, t, nl;

    b  = 0;
    t  = 0;
    nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++b;
        else if (c == '\t')
            ++t;
        else if (c == '\n')
            ++nl;
    }
    printf("Blanks:   %d\n", b);
    printf("Tabs:     %d\n", t);
    printf("Newlines: %d\n", nl);
}
