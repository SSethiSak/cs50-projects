#include <stdio.h>
#include <cs50.h>
int main()
{
    string name = get_string("whats your name?");
    string age = get_string("whats your age? ");
    string dog = get_string("what da dog doin? ");
    printf("you are %s " , name);
    printf("age %s " , age);
    printf("is %s \n", dog);
}