#include <stdio.h>

#define MAXWORDLEN 100

int main()
{
    int i, j;
    int c, nc, max;
    int hist[MAXWORDLEN];

    nc = max = 0;

    // initialize array
    for (i = 0; i < MAXWORDLEN; ++i)
        hist[i] = 0;

    // count words
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (nc > 0)
                ++hist[nc];
            if (max < hist[nc])
                max = hist[nc];
            nc = 0;
        } else
            ++nc;
    }

    // horizontal histogram
    for (i = 0; i < MAXWORDLEN; ++i)
        if (hist[i] > 0) {
            printf("%2d ", i);
            for (j = 0; j < hist[i]; ++j)
                putchar('*');
            putchar('\n');
        }

    putchar('\n');

    // vertical histogram
    while (0 < max) {
        for (i = 0; i < MAXWORDLEN; ++i) {
            if (hist[i] == 0)
                continue;
            if (max <= hist[i])
                printf(" * ");
            else
                printf("   ");
        }
        putchar('\n');
        --max;
    }

    for (i = 0; i < MAXWORDLEN; ++i)
        if (0 < hist[i])
            printf("%2d ", i);

    putchar('\n');
}
