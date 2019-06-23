/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet5: Speller (with "trie" data structure)

    NB: PSet5/Speller file with Andrey Tymofeiuk's code is dictionary.c,
    other additional files contain distribution code provided by Harvard CS50 staff

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2019

**/

// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;

// Represents a trie
node *root;

// Andrey Tymofeiuk: Declaring recursive helper function to unload the trie
void unloading_recursion(node *cursor);

// Andrey Tymofeiuk: Declaring global variable to count number of loaded words
int words_counter = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    // Initialize trie
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false;
    }
    root->is_word = false;
    for (int i = 0; i < N; i++)
    {
        root->children[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into trie
    // Andrey Tymofeiuk: Implemented by me
    while (fscanf(file, "%s", word) != EOF)
    {

        // Andrey Tymofeiuk: Determining the length of the current word
        int len_word = strlen(word);

        // Andrey Tymofeiuk: Setting counter to track current letter index
        int current_letter_index = 0;

        // Andrey Tymofeiuk: Creation of a trav node to traverse letter by letter through trie
        node *trav = root;

        // Andrey Tymofeiuk: Loop for letters; goes until current letter index equals the length of the word
        while (true)
        {
            // Andrey Tymofeiuk: Set is_word of a node to true. Increase counter. Escape the loop.
            if (current_letter_index == len_word)
            {
                trav->is_word = true;
                words_counter++;
                break;
            }

            // Andrey Tymofeiuk: Variable for determining the number of node
            int ascii_letter = 0;

            // Andrey Tymofeiuk: Check if this is apostrophe
            if ((int) word[current_letter_index] == 39)
            {
                ascii_letter = 26;
            }
            else
            {
                ascii_letter = tolower(word[current_letter_index]) - 'a';
            }

            // Andrey Tymofeiuk: Case if such letter does not exist yet
            if (trav->children[ascii_letter] == NULL)
            {

                // Andrey Tymofeiuk: Allocate memory for new node and initialize it
                node *new_node = malloc(sizeof(node));
                if (new_node == NULL)
                {
                    unload();
                    return false;
                }
                new_node->is_word = false;
                for (int i = 0; i < N; i++)
                {
                    new_node->children[i] = NULL;
                }

                // Andrey Tymofeiuk: That particular child of that letter is no more NULL, but points to new node
                // and therefore exists
                trav->children[ascii_letter] = new_node;
            }

            // Andrey Tymofeiuk: In any case, relocate trav to a new node
            trav = trav->children[ascii_letter];
            // Andrey Tymofeiuk: Increase letter counter
            current_letter_index++;
        }

    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
// Andrey Tymofeiuk: Implemented by me. Works with global variable words_counter
unsigned int size(void)
{
    if (words_counter > 0)
    {
        return words_counter;
    }
    return 0;
}

// Returns true if word is in dictionary else false
// Andrey Tymofeiuk: Implemented by me
bool check(const char *word)
{
    // Andrey Tymofeiuk: Declaring necessary indexes
    int len_word = strlen(word);
    int current_letter_index = 0;
    int ascii_letter = 0;

    // Andrey Tymofeiuk: Creating a checker node for traversing the trie until the end
    for (node *checker = root; checker != NULL; checker = checker->children[ascii_letter])
    {
        // Andrey Tymofeiuk: Assuring that we've found the right word
        if ((checker->is_word == true) && (current_letter_index == len_word))
        {
            return true;
        }

        // Andrey Tymofeiuk: Checking whether the letter is apostrophe
        ascii_letter = 0;
        if ((int) word[current_letter_index] == 39)
        {
            ascii_letter = 26;
        }
        else
        {
            ascii_letter = tolower(word[current_letter_index]) - 'a';
        }

        // Andrey Tymofeiuk: Necessary sanity check
        if (ascii_letter < 0 || ascii_letter > 26)
        {
            return false;
        }

        // Andrey Tymofeiuk: Step to the index of the next letter
        current_letter_index++;
    }
    return false;
}


// Unloads dictionary from memory, returning true if successful else false
// Andrey Tymofeiuk: Implemented by me
bool unload(void)
{
    // Andrey Tymofeiuk: Initializing of traverse node called deleter here
    node *deleter = root;

    // Andrey Tymofeiuk: Usage of helper function to unload recursively
    unloading_recursion(deleter);

    return true;
}

// Andrey Tymofeiuk: Helper function to unload recursively
void unloading_recursion(node *cursor)
{
    for (int i = 0; i < N; i++)
    {
        if (cursor->children[i] != NULL)
        {
            unloading_recursion(cursor->children[i]);
        }
    }
    free(cursor);
    return;
}
