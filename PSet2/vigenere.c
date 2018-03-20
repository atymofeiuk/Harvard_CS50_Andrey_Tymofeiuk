/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet2: Vigenere

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

**/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Andrey Tymofeiuk: Using argc and agrv to take info from user
int main(int argc, string argv[])
{
    // Andrey Tymofeiuk: Checking how many command-line arguments did user give
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    int key_len = 0;
    int chk = 0;
    string key = argv[1];

    while (key[chk] != '\0')
    {
        chk++;
        key_len++;
    }

    // Andrey Tymofeiuk: Checking whether given code is of letters
    for (int i = 0; i < key_len; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    // Andrey Tymofeiuk: Getting message from user
    string plaintext = get_string("plaintext: ");

    int text_len = 0;
    int chk2 = 0;
    while (plaintext[chk2] != '\0')
    {
        chk2++;
        text_len++;
    }

    char ciphertext[text_len];

    int text_c = 0;
    int key_c = 0;

    // Andrey Tymofeiuk: Applying Vigenere cipher
    while (plaintext[text_c] != '\0')
    {
        if (isalpha(plaintext[text_c]))
        {
            if (isupper(plaintext[text_c]))
            {
                if (isupper(key[key_c]))
                {
                    ciphertext[text_c] = (char) (65 + (((int) plaintext[text_c] - 65) + ((int) key[key_c] - 65)) % 26);
                    text_c++;
                    key_c++;
                }

                else
                {
                    ciphertext[text_c] = (char) (65 + (((int) plaintext[text_c] - 65) + ((int) key[key_c] - 97)) % 26);
                    text_c++;
                    key_c++;
                }
            }
            else
            {
                if (isupper(key[key_c]))
                {
                    ciphertext[text_c] = (char) (97 + (((int) plaintext[text_c] - 97) + ((int) key[key_c] - 65)) % 26);
                    text_c++;
                    key_c++;
                }
                else
                {
                    ciphertext[text_c] = (char) (97 + (((int) plaintext[text_c] - 97) + ((int) key[key_c] - 97)) % 26);
                    text_c++;
                    key_c++;
                }
            }

        }
        else
        {
            ciphertext[text_c] = plaintext[text_c];
            text_c++;
        }

        if (key_c == key_len)
            key_c = 0;
    }

    printf("ciphertext: ");

    for (int i = 0; i < text_len; i++)
        printf("%c", ciphertext[i]);

    printf("\n");
}