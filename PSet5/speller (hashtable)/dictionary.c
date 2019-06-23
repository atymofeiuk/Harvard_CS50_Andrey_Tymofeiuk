/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet5: Speller

    NB: PSet5/Speller file with Andrey Tymofeiuk's code is dictionary.c,
    other additional files contain distribution code provided by Harvard CS50 staff

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2017

**/

// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"
int words_counter = 0;

// Andrey Tymofeiuk: Structure of nodes (word itself and a pointer to the next one)

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Andrey Tymofeiuk: Creation of a hash_table as an array of 25 nodes according to 26 letters in Latin alphabet
node *hash_table[25];

// Andrey Tymofeiuk: Hash function implemented by me
int hash_function(const char *buffer)
{
    char first_lower = tolower(buffer[0]);

    // Andrey Tymofeiuk: Getting the number of a bucket
    int letter_order = (int) first_lower - 97;

    // Andrey Tymofeiuk: Hash-function returns the integer, which is the number of the bucket
    return letter_order;
}

// Andrey Tymofeiuk: Check function implemented by me
bool check(const char *word)
{
    // Andrey Tymofeiuk: Getting to the proper bucket
    int bucket_number = hash_function(word);
    node *cursor = hash_table[bucket_number];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    // Andrey Tymofeiuk: Placing pointer to the dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        unload();
        return false;
    }

    // Andrey Tymofeiuk: Creating a buffer for a string
    char *buffer_word = malloc(sizeof(char) * (LENGTH + 1));

    // Andrey Tymofeiuk: Main loop for the words in a dictionary
    while (fscanf(dict, "%s", buffer_word) != EOF)
    {
        // Andrey Tymofeiuk: Creating a new node
        node *new_node = malloc(sizeof(node));
        new_node->next = NULL;

        // Andrey Tymofeiuk: Copying a string from the dictionary to the new node
        strcpy(new_node->word, buffer_word);

        // Andrey Tymofeiuk: Launching hash-function to determine correct bucket number
        int bucket_number = hash_function(buffer_word);

        // Andrey Tymofeiuk: Placing the new node according to its bucket number
        if (hash_table[bucket_number] != NULL)
        {
            new_node->next = hash_table[bucket_number]->next;
            hash_table[bucket_number]->next = new_node;
            words_counter++;
        }
        else
        {
            hash_table[bucket_number] = new_node;
            words_counter++;
        }
    }

    free(buffer_word);
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
// Andrey Tymofeiuk: Implemented by me
unsigned int size(void)
{

    if (words_counter > 0)
    {
        return words_counter;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
// Andrey Tymofeiuk: Implemented by me
bool unload(void)
{
    for (int i = 0; i < 26; i++)
    {
        node *deleter = hash_table[i];

        while (deleter != NULL)
        {
            node *temp = deleter;
            deleter = deleter->next;
            free(temp);
        }
    }
    return true;
}
