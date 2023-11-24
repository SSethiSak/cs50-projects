// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 200000;
int sizes = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int x = hash(word);
    node *trv = table[x];

    while (trv != 0)
    {
        if (strcasecmp(word,trv->word) == 0)
        {
            return true;
        }

        trv = trv->next;
    }

    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int x = 0, sum = 0;
   for (int i = 0; i < 3; i++)
   {
        x = toupper(word[i]) - 65;
        sum = sum + x;

   }
    // TODO: Improve this hash function
    return sum % N;
}



// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary,"r");//open dictionary in read

    if (dict == NULL)//if cant open
    {
        fclose(dict);
        printf("Could not open dictionary file\n");
        return false;
    }
    char buffer[LENGTH + 1];

    int count = 0;//for counting word

    while((fscanf(dict, "%s", buffer)) != EOF)
    {
        count++;
        node *NEW = malloc(sizeof(node));//create new node for new word
        if (NEW == NULL)
        {
            free(NEW);
            printf("no memory to allocate\n");
            return false;
        }

        strcpy(NEW->word, buffer);//put word from buffer array into our node of linked list
        unsigned int x = hash(NEW->word);

        if (table[x] != NULL)//if theres stuff at the xth index just insert node into it and update table pointer to point at new
        {
            NEW->next = table[x];
            table[x] = NEW;
        }

        else NEW->next = NULL;
        table[x] = NEW;// make the xth pointer of hash table point to our new word's node
    }
int *sizeglob = &sizes;
*sizeglob = count;
fclose(dict);
return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    return sizes;
    // TODO
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{


    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
            while (ptr != 0)
            {
                node *tmp = ptr->next;
                free(ptr);
                ptr = tmp;


            }

    }
    // TODO
    return true;

}

