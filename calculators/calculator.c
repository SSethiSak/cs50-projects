#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
    int x = get_int("x = ");
    char i = get_char("do what: ");
    int y = get_int("y = ");

    if (i == '+')
    {
        printf("%i + %i = %i \n", x, y, x + y);
    }

    if (i == '-')
    {
        printf("%i", x - y);
    }


    if (i == '/')
    {
        printf("%i", x / y);
    }

    if (i == '*')
    {
        printf("%i", x * y);
    }



    printf("\n");




}
