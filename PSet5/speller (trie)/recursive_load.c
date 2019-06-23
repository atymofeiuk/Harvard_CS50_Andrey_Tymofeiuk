
void loading_recursion(node *trav, int length_word, char word[LENGTH + 1], int current_letter_index)
{

    // Andrey Tymofeiuk: Check whether the word is already at the last letter
    if (current_letter_index == length_word)
    {
        trav->is_word = true;
        words_counter++;
        return;
    }

    // Andrey Tymofeiuk: Getting the alphabet number of a letter
    int ascii_letter = 0;
    if ( (int) word[current_letter_index] == 39)
    {
        ascii_letter = 26;
    }
    else
    {
        ascii_letter = tolower(word[current_letter_index]) - 'a';
    }

    // Andrey Tymofeiuk: Increasing letters count to check the end of the word
    int current_letter_index_upd = current_letter_index + 1;

    if (trav->children[ascii_letter] != NULL)
    {
        return loading_recursion(trav->children[ascii_letter], length_word, word, current_letter_index_upd);
    }

    // Andrey Tymofeiuk: Creation and initialisation of a new node
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        unload();
        return;
    }
    new_node->is_word = false;
    for (int i = 0; i < N; i++)
    {
        new_node->children[i] = NULL;
    }

    // Andrey Tymofeiuk: Putting new node to the corresponding children route
    trav->children[ascii_letter] = new_node;

    // Andrey Tymofeiuk: Recursion dive
    return loading_recursion(new_node, length_word, word, current_letter_index_upd);
}


        // Andrey Tymodeiuk: Using recursion function
        //loading_recursion(root, len_word, word, 0);
