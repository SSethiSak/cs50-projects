#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char cipher(string text,int key);// function for ciphering the message using the text and the key
bool only_digits(string digits);// function for checking for if the input is a number digit


int main() //user must use ./caesar (key they wish to use to cipher their text)
{

int k = get_int("key: "); //convert each array of the argument into interger as they are string

    if (isdigit(k))// check to see if user only input 1 argument
    {
        printf("usage : ./caesar key\n");
        return 1;
    }



    string plaintext = get_string("plaintexts:  "); //plaintext user want to cipher

     printf("ciphertexts:");
    cipher(plaintext,k); //cipher the text with the key
        printf("\n");
}










char cipher(string text,int key)
 {
     for(int p=0; p < strlen(text); p++)
        {
            if  (isupper(text[p]))
            {
                printf("%c", (text[p] - 65 + key)%26 + 65);
            }
            else if (islower(text[p]))
            {
                printf("%c", (text[p] - 97 +key)%26 + 97);
            }
            else printf("%c", text[p]);
        }
        return 0;
 }














bool only_digits(string digits)
{

    for (int i = 0; i < strlen(digits); i++)
        {
            if (!isdigit(digits[i]))
            {
                printf("usage : ./caesar key \n");
                return 1;
            }

        }

        return 0;

}