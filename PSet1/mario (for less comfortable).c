/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet1: Mario (less comfortable)

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2017

**/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    // Andrey Tymofeiuk: Asking user to give correct height until he or she gives it
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while ((height < 0) || (height > 23));

    // Andrey Tymofeiuk: Handling the 0-height case
    if (height == 0)
        return 0;

    printf("\n");

    // Andrey Tymofeiuk: Main loop
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i + 2; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}