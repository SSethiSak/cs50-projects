#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size have to be larger than 9
   int n;
    do
    {
        n = get_int("starting population size of llamas: ");
    }
    while (n < 9);
    // TODO: Prompt for end size
    int e;
    do
    {
       e = get_int("end size of populations: ");
    }
    while (e < n);
    // TODO: Calculate number of years until we reach threshold

    int a=0;
    while (n < e)
    {
    n = n + n / 3 - n / 4;
    a++;
    }
    // TODO: Print number of years
    printf("num of year: %i \n", a);


}