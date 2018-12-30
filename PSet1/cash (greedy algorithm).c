/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet1: Cash ("greedy algorithm")

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2017

**/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

float dollars_left;
int cents_left;
int quarter = 25; int dime = 10; int nickel = 5; int pennie = 1;
int total_count, q_count, d_count, n_count, p_count;

int main(void)
{
    // Andrey Tymofeiuk: Asking user for correct input
    printf("O hai! ");
    do
    {
        printf("How much change is owed?\n");
        dollars_left = get_float();
    }
    while (dollars_left < 0);

    // Andrey Tymofeiuk: Getting from dollars to cents and rounding
    cents_left = round(dollars_left*100);

    // Andrey Tymofeiuk: Substracting coins in different loops

    while (cents_left >= quarter)
    {
        cents_left = cents_left - quarter;
        q_count++;
    }

    while (cents_left >= dime)
    {
        cents_left = cents_left - dime;
        d_count++;
    }

    while (cents_left >= nickel)
    {
        cents_left = cents_left - nickel;
        n_count++;
    }

    while (cents_left >= pennie)
    {
        cents_left = cents_left - pennie;
        p_count++;
    }

    // Andrey Tymofeiuk: Summary number of coins
    total_count = q_count + d_count + n_count + p_count;

    printf("%i\n", total_count);
}



