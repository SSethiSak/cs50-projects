#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string texts);
int count_words(string texts);
int count_sentences(string texts);


int main(void)
{
    string texts = get_string("text: ");

    int letterc = count_letters(texts);
    int wordc = count_words(texts);
    int sentencec = count_sentences(texts);


    //printf("%s \n", texts);
    //printf("letters : %i  \n", letterc);
    //printf("words : %i  \n", wordc);
    //printf("sentences : %i  \n", sentencec);

    float L = 100 * letterc / wordc; // L = average letter in 100 words
    float S = 100 * sentencec / wordc; // S = average sentence in 100 words
    int index = round(0.0588 * L - 0.296 * S - 15.800);

    if (index >= 1 && index <= 16)
    {
         printf("Grade %i\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    printf("Grade 16+\n");


}





   int count_letters(string texts)
    {
        int letters = 0;
        for (int i=0; i < strlen(texts); i++)
        {
            if (texts[i] > 96 && texts[i] < 122)
            {
                 letters = letters + 1;
            }
            else if (texts[i] > 64 && texts[i] < 91)
            {
                  letters = letters + 1;
            }
            else letters = letters + 0;

        }
        return letters;
    }

    int count_words(string texts)
    {
        int words = 1;
        for (int w = 0; w < strlen(texts); w++)
        {
            if (isblank(texts[w]))
            {
                words = words + 1;
            }
            else words = words + 0;
        }
        return words;
    }


    int count_sentences(string texts)
    {
        int sentences = 0;
        for (int s = 0; s < strlen(texts); s++)
        {
            if (texts[s] == 46 || texts[s] == 33 || texts[s] == 63)
            {
                sentences = sentences + 1;
            }
        }
        return sentences;
    }