#include <stdio.h>

#define TRUE  1
#define FALSE 0

int main(void)
{
    /* char tracking */
    int c, prev;

    /* states */
    int comment, string, character, quote;

    comment = string = character = quote = 0;
    prev = 0;

    while ((c = getchar()) != EOF) {

        /* close  */
        if (comment) {
            if ('/' == c && prev == '*') {
                comment = FALSE;
                continue;
            }
        }
        else if (quote) {
            quote = FALSE;
        }
        else if (string) {
            if ('"' == c) {
                string = FALSE;
            }
        }
        else if (character) {
            if ('\'' == c) {
                character = FALSE;
            }
        }

        /* open */
        else if ('*' == c && prev == '/') {
            comment = TRUE;
        }
        else if ('"' == c) {
            string = TRUE;
        }
        else if ('\'' == c) {
            character = TRUE;
        }

        if ('\\' == c && '\\' != prev) {
            quote = TRUE;
        }

        if ('/' == prev && !comment)
            putchar('/');

        prev = c;

        if (comment)
            continue;

        if ('/' == c)
            continue;

        putchar(c);
    }

    return 0;
}
