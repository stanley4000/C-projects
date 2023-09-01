// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
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
const unsigned int N = 1000;

// Hash table header
node *table[N];

//dictionary size variable for counting words
int dict_size = 0;

// Temp variable for copying word from dictionary to node
char next_word[LENGTH + 1];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Get hash value for word
    int hash_value = hash(word);

    // access linked list at that hash value (create cursor)
    node *cursor = table[hash_value];

    // Traverse linked list, checking for match (case insensitive)
    while (cursor != NULL)
    {
        // Note: strcasecomp returns 0 for a match
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        // Move to next item in linked list
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    // //  hashes by value of first letter
    // return toupper(word[0]) - 'A';


    // This hash function totals the ASCII values in the word
    long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open input file for reading (dictionary)
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    //for each word in dictionary, fscanf until EOF (end of file)

    while (fscanf(inptr, "%s", next_word) != EOF)
    {
        // malloc node
        node *n = malloc(sizeof(node));
        // Check for null
        if (n == NULL)
        {
            return false;
        }
        // Copy word into node
        strcpy(n->word, next_word);

        // Get hash value
        int hash_value = hash(next_word);

        // new node takes pointer of current header
        n->next = table[hash_value];
        // header redirects to new node
        table[hash_value] = n;

        // increase number of words
        dict_size++;

    }
    fclose(inptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // returns size of dictionary loaded into hash table
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Loop through each of N linked lists
    for (int i = 0; i < N; i++)
    {
        // set cursor to header
        node *cursor = table[i];
        // loop through linked list
        while (cursor != NULL)
        {
            // store current cursor
            node *temp = cursor;
            // move cursor forward
            cursor = cursor->next;
            //free temp
            free(temp);
        }
    }

    return true;
}
