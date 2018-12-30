/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include "helpers.h"

void merge(int left_array[], int right_array[], int n1, int n2);

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
void sort(int values[], int n)
{
    // Andrey Tymofeiuk: My recursive implementation of merge sort

    if (n < 2)
        return;

    int left_array[n/2 + n%2];
    for (int i = 0; i < n/2 + n%2; i++)
        left_array[i] = values[i];

    int right_array[n/2];
    for (int i = n/2; i < n; i++)
        right_array[i] = values[i];

    sort(left_array, n/2 + n%2);
    sort(right_array, n/2);

    merge(left_array, right_array, n/2 + n%2, n/2);
}

void merge(int left_array[], int right_array[], int n1, int n2)
{
    int temp[n1+n2];
    int tracker = 0;
    int left_c = 0;
    int right_c = 0;

    while (tracker < n1+n2)
    {

        if (left_c >= n1)
        {
            temp[tracker] = right_array[right_c];
            right_c++;
            tracker++;
        }

        else if (right_c >= n2)
        {
            temp[tracker] = left_array[left_c];
            left_c++;
            tracker++;
        }

        else if ((left_array[left_c] >= right_array[right_c]) && (left_c < n1))
        {
            temp[tracker] = left_array[left_c];
            left_c++;
            tracker++;
        }
        else if ((left_array[left_c] < right_array[right_c]) && (right_c < n2))
        {
            temp[tracker] = right_array[right_c];
            right_c++;
            tracker++;
        }
    }

    for (int i = 0; i < n1; i++)
        left_array[i] = temp[i];

    for (int i = n1; i < n2; i++)
        right_array[i] = temp[i];

}