/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet1: Water

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

int main(void)
{
    // Andrey Tymofeiuk: Getting the number of minutes from the user
    printf("Minutes: ");
    float minutes = get_int();

    // Andrey Tymofeiuk: Calculations
    float gallons = minutes * 1.5;
    float ounces = gallons * 128;
    int bottles = round(ounces/16) ;

    printf("Bottles: %d\n", bottles);
}
