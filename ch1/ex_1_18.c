#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (1 < len) {
            for (len=len-1; line[len] == ' ' || line[len] == '\t' || line[len] == '\n'; --len)
                ;
            line[++len] = '\n';
            line[++len] = '\0';
            printf("%s", line);
        }
    }
    return 0;
}

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
