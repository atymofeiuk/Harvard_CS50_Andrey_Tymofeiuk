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
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
// Andrey Tymofeiuk: Recursive binary search implementation
bool search(int value, int values[], int n)
{
    if ((n == 2) && ((values[0] == value) || (values[1] == value)))
        return true;

    if (values[0] >= values[n-1])
        return false;

    if (value == values[n/2])
        return true;

    else if (value < values[n/2])
    {
        int new_values[(n/2) + (n%2)];
        for (int i = 0; i < (n/2) + (n%2); i++)
            new_values[i] = values[i];

        return search(value, new_values, (n/2)+(n%2));
    }
    else if (value > values[n/2])
    {
        int new_values[(n/2) + (n%2)];
        for (int i = (n/2) + (n%2); i < n; i++)
            new_values[i - n/2 - n%2] = values[i];

        return search(value, new_values, (n/2)+(n%2));
    }

    else
        return false;
}

/**
 * Sorts array of n values.
 */
// Andrey Tymofeiuk: My implementation of bubble sort
void sort(int values[], int n)
{

    int counter = -1;
    while (counter != 0)
    {
        counter = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (values[i] > values[i+1])
            {
                int temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                counter++;
            }
        }
    }
}