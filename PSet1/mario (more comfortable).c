/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet1: Mario (more comfortable)

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

**/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int len = 0;
    
    // Andrey Tymofeiuk: Check for the correct input
    do
    {
        len = get_int("Height: ");
    }
    while ((len < 0) || (len > 23));

    // Andrey Tymofeiuk: Main loop
    for (int i = 1; i < len + 1; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf(" ");
        printf(" ");

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}