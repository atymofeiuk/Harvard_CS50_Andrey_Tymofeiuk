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
// Andrey Tymofeiuk: My iterative binary search implementation
bool search(int value, int values[], int n)
{

    // Andrey Tymofeiuk: Test for non-emptiness of the array
    if (n <= 0)
        return false;

    // Andrey Tymofeiuk: Binary search

    int lower_bound = 0;
    int upper_bound = n-1;

    while (true)
    {
        int middle = (upper_bound-lower_bound)/2+lower_bound;
        if ((value == values[middle]) || (value == values[upper_bound]) || (value == values[lower_bound]))
        {
            return true;
        }
        if ((lower_bound >= upper_bound) || (((middle == lower_bound) || (middle == upper_bound)) && value != values[middle]))
        {
            return false;
        }
        if (value < values[middle])
            upper_bound = middle;

        else if (value > values[middle])
            lower_bound = middle;
    }

}


/**
 * Sorts array of n values.
 */
// Andrey Tymofeiuk: My implementation of the "counter sorting algorithm" of O(n) complexity
void sort(int values[], int n)
{

    // Andrey Tymofeiuk: Search for the max element of the array to create "counting" array
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (values[i] > max)
            max = values[i];
    }

    // Andrey Tymofeiuk: Creation of "counting" array
    int counting_array[max];
    for (int i2 = 0; i2 < max; i2++)
        counting_array[i2] = 0;

    // Andrey Tymofeiuk: Filling of "counting" array
    for (int j = 0; j < n; j++)
    {
        if (values[j] != 0)
            counting_array[values[j]-1]++;
    }

    // Andrey Tymofeiuk: Creation of new sorted array
    int sorted_array[n];
    int slot = 0;
    for (int j2 = 0; j2 < max; j2++)
    {
        if (counting_array[j2] != 0)
        {
            for (int i3 = 0; i3 < counting_array[j2]; i3++)
            {
                sorted_array[slot] = j2+1;
                slot++;
            }
        }
    }

    // Andrey Tymofeiuk: Changing the initial array
    for (int i3 = 0; i3 < n; i3++)
        values[i3] = sorted_array[i3];
}
