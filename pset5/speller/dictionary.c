// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

#include "dictionary.h"
#define HASHSIZE 101

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 101;

// Hash table
node *table[N];

node *n = NULL;

int total = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hsh = 0;
    //find hash of the word
    hsh = hash(word);
    node *s = table[hsh];
    if (s == NULL)
    {
        return false;
    }

    //lookup for the word in the lnked lists array
    for (int i = 0; i < HASHSIZE ; i++)
    {
        if (table[i] != NULL)
        {
            s = table[i];
            while (true)
            {
                if (strcasecmp(word, s -> word) == 0)
                {
                    return true;
                }

                if (s -> next == NULL)
                {
                    break;
                }
                else
                {
                    s = s ->next ;
                }
            }

        }
    }






    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    /*   ***************************************************************************************/
    /*   Title: The C Programming Language - Book - 2nd Edition
    *    Author: Brian W. Kernighan & Dennis M.Ritchie
    *    Date: 1988
    *    Code version: --- section 6.6 in the book
    *    Availability: https://www.amazon.com/dp/0131103628
    *
    ***************************************************************************************/

    unsigned hashval;
    for (hashval = 0; *word != '\0'; word++)
    {
        hashval = toupper(*(word)) + 31 * hashval;
    }
    return hashval % HASHSIZE;
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];
    int hsh = 0;

    //reset the hash table
    for (int i = 0; i < N ; i++)
    {
        table[i] = NULL;
    }

    //open the dictionary file
    FILE *fp = fopen(dictionary, "r") ;
    if (fp == NULL)
    {
        return false;
    }
    else
    {
        //fetch each word
        while (fscanf(fp, "%s", word) != EOF)
        {
            total++;
            n = malloc(sizeof(node));
            if (n == NULL)
            {
                return false;
            }
            strcpy(n -> word, word);
            hsh = hash(word);

            if (table[hsh] == NULL)
            {
                table[hsh] = n;
                n -> next = NULL;
            }
            else
            {
                n -> next = table[hsh] ;
                table[hsh] = n;
            }

        }

        fclose(fp);
        return true;

    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    node *s = NULL;
    int count = 0;
    //loop through the arrays of linked lists
    for (int i = 0; i < HASHSIZE ; i++)
    {
        if (table[i] != NULL)
        {
            s = table[i];
            while (true)
            {
                count++;
                if (s -> next == NULL)
                {
                    break;
                }
                else
                {
                    s = s ->next ;
                }
            }

        }
    }

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    total = 0;
    node *temp = NULL;
    node *cursor = NULL;
    int del = 0;

    //free the dynamic node memory blocks
    for (int i = 0; i < HASHSIZE ; i++)
    {
        if (table[i] != NULL)
        {
            cursor = table[i];
            while (true)
            {
                temp = cursor;
                if (cursor -> next == NULL)
                {
                    free(temp);
                    del ++;
                    total++;
                    break;
                }
                else
                {

                    cursor = cursor ->next ;
                    free(temp);
                    del++;
                    total++;
                }

            }

        }
        else
        {
            del++;
        }

    }
    if (del == 0)
    {
        return false;
    }
    else
    {
        return true;
    }

}
