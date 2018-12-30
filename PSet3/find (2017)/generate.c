/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet3: Find

    NB: PSet3/Find file with Andrey Tymofeiuk's code is helpers.c (all the variationss of this file in the folder),
    other additional files contain distribution code provided by Harvard CS50 staff

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2017

**/

/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Andrey Tymofeiuk: Checks whether input is ok
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // Andrey Tymofeiuk: Transfers second command into integer (how many numbers to generate)
    int n = atoi(argv[1]);

    // Andrey Tymofeiuk: Seeks for the seed
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // Andrey Tymofeiuk: Prints the result
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // Andrey Tymofeiuk: Success
    return 0;
}
