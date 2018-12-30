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
// Andrey Tymofeiuk: My implementation of insertion sort
void sort(int values[], int n)
{
    int k = 0;

    while (k < n)
    {
        int j = k;

        while ((j>0) && (values[j-1] > values[j]))
        {
            int temp = values[j-1];
            values[j-1] = values[j];
            values[j] = temp;
            j--;
        }
        k++;
    }
}