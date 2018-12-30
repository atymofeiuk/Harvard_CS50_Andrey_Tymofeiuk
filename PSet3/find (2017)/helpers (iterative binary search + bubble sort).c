/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet3: Find (iterative binary search + bubble sort)

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

    // Andrey Tymofeiuk: Iterative binary search
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