/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet2: Caesar

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2017

**/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

// Andrey Tymofeiuk: Using argc and agrv to take info from user
int main(int argc, string argv[])
{
    // Andrey Tymofeiuk: Checking how many command-line arguments did usage give
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // Andrey Tymofeiuk: Making integer of a string
    int k = atoi(argv[1]);

    // Andrey Tymofeiuk: Checking whether integer is valid for Caesar cipher
    if (k < 1)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // Andrey Tymofeiuk: Getting message from user
    printf("plaintext: ");
    string message = get_string();

    // Andrey Tymofeiuk: Applying Caesar cipher
    printf("ciphertext: ");
    for (int i = 0; i < strlen(message); i++)
    {
        if (((int) message[i] >= 65) && ((int) message[i] < 91))
        {
            message[i] = ((int) message[i] - 65 + k) % 26 + 65;
            printf("%c", (char) message[i]);
        }

        else if (((int) message[i] >= 97) && ((int) message[i] < 123))
        {
            message[i] = ((int) message[i] - 97 + k) % 26 + 97;
            printf("%c", (char) message[i]);
        }

        else
            printf("%c", (char) message[i]);
    }

    // Andrey Tymofeiuk: Final step
    printf("\n");
    return 0;
}