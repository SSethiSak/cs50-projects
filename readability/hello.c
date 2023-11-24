#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
int main()
{
    string s = get_string("s:");

    printf("%s\n", s);
    string up = s;
    up[0] = toupper(up[0]);
    printf("%s\n", up);
}