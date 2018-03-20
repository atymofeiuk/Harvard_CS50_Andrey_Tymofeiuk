/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet2: Crack ("hacker edition" / for "more comfortable")

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2017

**/

#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <crypt.h>
#include <ctype.h>
#include <string.h>

#define _XOPEN_SOURCE
#define _GNU_SOURCE

// Compile: clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow crack.c -lcrypt -lcs50 -lm -o crack

int main(int argc, string argv[])
{
    // Andrey Tymofeiuk: Checking how many command-line arguments did user give
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    // Andrey Tymofeiuk: Getting hash from the user
    string hash_t = argv[1];


    // Andrey Tymofeiuk: Getting the salt as the two first digits of the input
    char *salt_t;
    salt_t = (char*) malloc(2*sizeof(char));
    strncpy(salt_t, hash_t, 2);

    // Andrey Tymofeiuk: Creating a copy of the hash
    char *copy_hash_t;
    copy_hash_t = (char*) malloc(strlen(hash_t)*sizeof(char));
    strncpy(copy_hash_t, hash_t, strlen(hash_t));


    // Andrey Tymofeiuk: Main loop!
    for (int j = 1; j < 5; j++)
    {
        // Andrey Tymofeiuk: Check whether the word consists of one character; brute force
        if (j == 1)
        {
            for (int i = 65; i < 123; i++)
            {
                char ascii_value = (char) i;

                if (isalpha(ascii_value))
                {
                    char *possible_message;
                    possible_message = (char*) malloc(sizeof(char));

                    char ascii_values_array[1];
                    ascii_values_array[0] = ascii_value;
                    strncpy(possible_message, ascii_values_array, 1);
                    char *hash_mystery;
                    hash_mystery = crypt(possible_message, salt_t);

                    int comparison;
                    comparison = strcmp(hash_mystery, copy_hash_t);
                    if (comparison == 0)
                    {
                        printf("%s\n", possible_message);
                        return 0;
                    }
                }

            }
        }

        // Andrey Tymofeiuk: Check whether the word consists of two characters; brute force
        else if (j == 2)
        {
            for (int i_21 = 65; i_21 < 123; i_21++)
            {
                char ascii_value = (char) i_21;

                if (isalpha(ascii_value))
                {
                    char *possible_message2;
                    possible_message2 = (char*) malloc(2*sizeof(char));

                    char ascii_values_array[2];
                    ascii_values_array[0] = ascii_value;

                    for (int i_22 = 65; i_22 < 123; i_22++)
                    {
                        char ascii_value2 = (char) i_22;

                        if (isalpha(ascii_value2))
                        {
                            ascii_values_array[1] = ascii_value2;
                            strncpy(possible_message2, ascii_values_array, 2);

                            char *hash_mystery2;
                            hash_mystery2 = crypt(possible_message2, salt_t);

                            int comparison;
                            comparison = strcmp(hash_mystery2, copy_hash_t);
                            if (comparison == 0)
                            {
                                printf("%s\n", possible_message2);
                                return 0;
                            }
                        }
                    }
                }
            }
        }

        // Andrey Tymofeiuk: Check whether the word consists of three characters; brute force
        else if (j == 3)
        {
            for (int i_31 = 65; i_31 < 123; i_31++)
            {
                char ascii_value_31 = (char) i_31;

                if (isalpha(ascii_value_31))
                {
                    char *possible_message3;
                    possible_message3 = (char*) malloc(3*sizeof(char));

                    char ascii_values_array[3];
                    ascii_values_array[0] = ascii_value_31;

                    for (int i_32 = 65; i_32 < 123; i_32++)
                    {
                        char ascii_value_32 = (char) i_32;
                        ascii_values_array[1] = ascii_value_32;

                        if (isalpha(ascii_value_32))
                        {
                            for (int i_33 = 65; i_33 < 123; i_33++)
                            {
                                char ascii_value_33 = (char) i_33;
                                ascii_values_array[2] = ascii_value_33;

                                if (isalpha(ascii_value_33))
                                {
                                    strncpy(possible_message3, ascii_values_array, 3);

                                    char *hash_mystery3;
                                    hash_mystery3 = crypt(possible_message3, salt_t);

                                    int comparison;
                                    comparison = strcmp(hash_mystery3, copy_hash_t);
                                    if (comparison == 0)
                                    {
                                        printf("%s\n", possible_message3);
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // Andrey Tymofeiuk: Check whether the word consists of four characters; brute force
        else if (j == 4)
        {
            for (int i_41 = 65; i_41 < 123; i_41++)
            {
                char ascii_value_41 = (char) i_41;

                if (isalpha(ascii_value_41))
                {
                    char *possible_message4;
                    possible_message4 = (char*) malloc(4*sizeof(char));

                    char ascii_values_array[4];
                    ascii_values_array[0] = ascii_value_41;

                    for (int i_42 = 65; i_42 < 123; i_42++)
                    {
                        char ascii_value_42 = (char) i_42;
                        ascii_values_array[1] = ascii_value_42;

                        if (isalpha(ascii_value_42))
                        {
                            for (int i_43 = 65; i_43 < 123; i_43++)
                            {
                                char ascii_value_43 = (char) i_43;
                                ascii_values_array[2] = ascii_value_43;

                                if (isalpha(ascii_value_43))
                                {
                                    for (int i_44 = 65; i_44 < 123; i_44++)
                                    {
                                        char ascii_value_44 = (char) i_44;
                                        ascii_values_array[3] = ascii_value_44;

                                        if (isalpha(ascii_value_44))
                                        {
                                            strncpy(possible_message4, ascii_values_array, 4);

                                            char *hash_mystery4;
                                            hash_mystery4 = crypt(possible_message4, salt_t);

                                            int comparison;
                                            comparison = strcmp(hash_mystery4, copy_hash_t);
                                            if (comparison == 0)
                                            {
                                                printf("%s\n", possible_message4);
                                                return 0;
                                            }

                                        }
                                    }


                                }
                        }}
                    }
                }
            }
        }
}
    return 0;
}