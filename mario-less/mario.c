#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for input on how tall pyramid should be
    // the interger must be between 1-8

     int n;
    do
    {
       n = get_int("how tall should the pyramid be? ");
    }
    while (n > 8 || n < 1);
    // build the pyramid with the int n or print the pyramid

     int i;
     int k;
     int j;
     for (i=0; i < n; i++)
     {
      for (k=0; k < n - i - 1; k++)
      {
         printf(" ");
      }

      for (j=0; j < i; j++)
      {
         printf("#");
      }
      printf(" \n");
       }
}