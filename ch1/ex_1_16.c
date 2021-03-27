#include <stdio.h>
#define MAXLINE 10 /* maximum input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    int seg; /* length of line segment */

    char line[MAXLINE];    /* current input line */
    char bline[MAXLINE];   /* beginning input line */
    char longest[MAXLINE]; /* longest line saved here */

    seg = max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0) {

        if (seg == 0)
            copy(bline, line);

        seg += len;

        if (line[len-1] == '\n') {

            if (max < seg) {
                copy(longest, bline);
                max = seg;
            }
            seg = 0;
        }
    }
    if (max > 0) {
        printf("max: %d\n", max);
        printf("longest: %s\n", longest);
    }
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

/* copy: copy 'from' into 'to': assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
