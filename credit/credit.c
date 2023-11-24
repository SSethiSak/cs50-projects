#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long count = 0;
    long card1, card2;
    long power1, power2, power3;
    long id = get_long("number:");
    long copy = id;
    int n = 0;

    while (copy > 0)
    {
        copy /= 10;
        n++;
    }
 //later code so that n is equal to the amount of digit in either visa mastercard,......
    for (int j = 2; j <= 16; j = j + 2)
    {
        power1 = pow(10, j);
        power2 = pow(10, j - 1);
        power3 = pow(10, j - 2);
        card1 = ((id % power1)/ power2)* 2;
        card1 = (card1 % 100/10) + (card1 % 10);

        card2 = ((id % power2)/ power3);


        count = count +card1 + card2;
    }
    if (count % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long visa = id;
    while (visa >= 10)
    {
        visa /= 10;
    }
    if (visa == 4 && (n == 13 || n == 16))
    {
        printf("VISA\n");
        return 0;
    }
    long MasAme = id;
    while (MasAme >= 100)
    {
        MasAme /= 10;
    }
    if ((MasAme == 34 || MasAme == 37) && n ==15)
    {
        printf("AMEX\n");
        return 0;
    }
    if ((MasAme == 51 || MasAme == 52 || MasAme == 53 || MasAme == 54 || MasAme == 55) && n == 16)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    printf("INVALID\n");
    return 0;
}