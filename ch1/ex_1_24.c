#include <stdio.h>

#define TRUE  1
#define FALSE 0

int main(void)
{
    /* char tracking */
    int c, prev;
    prev = 0;

    /* global states */
    int comment, string, character, quote;
    comment = string = character = quote = 0;

    /* counts */
    int cparen, cbrace, cbracket;
    cparen = cbrace = cbracket = 0;

    while ((c = getchar()) != EOF) {

        /* close state */
        if (comment) {
            if ('/' == c && prev == '*') {
                comment = FALSE;
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

        /* open state */
        else if ('*' == c && prev == '/') {
            comment = TRUE;
        }
        else if ('"' == c) {
            string = TRUE;
        }
        else if ('\'' == c) {
            character = TRUE;
        }

        /* count open / close */
        else if ('(' == c) {
            ++cparen;
        }
        else if (')' == c) {
            --cparen;
        }
        else if ('[' == c) {
            ++cbrace;
        }
        else if (']' == c) {
            --cbrace;
        }
        else if ('{' == c) {
            ++cbracket;
        }
        else if ('}' == c) {
            --cbracket;
        }

        if ('\\' == c && '\\' != prev) {
            quote = TRUE;
        }

        prev = c;
    }

    if (cparen)
        printf("Unbalanced parenthesis detected\n");
    if (cbrace)
        printf("Unbalanced brace detected\n");
    if (cbracket)
        printf("Unbalanced bracket detected\n");

}
