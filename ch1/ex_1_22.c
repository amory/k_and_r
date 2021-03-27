#include <stdio.h>

#define WRAP 10
#define TABSIZE 8

int getword(char word[], int lim);

int main(void)
{
    int len, pos;
    char word[WRAP+1];

    pos = 0;
    while ((len = getword(word, WRAP+1)) > 0) {
        pos += len;

        // handle tab
        if ('\t' == word[len-1])
            pos += TABSIZE - ((pos-1) % TABSIZE);

        if (WRAP <= pos) {
            putchar('\n');
            pos = len;
        }
        printf("%s", word);
    }
}

int getword(char word[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF; ++i) {
        word[i] = c;
        if (' ' == c || '\n' == c || '\t' == c) {
            ++i;
            break;
        }
    }
    word[i] = '\0';
    return i;
}
