#include<stdio.h>
#include<stdlib.h>
int main()
{
    ungetc('a',stdin);
    printf("%c",getchar());
    ungetc('b',stdin);
    ungetc('c',stdin);
    printf("%c",getchar());
    printf("%c",getchar());

}