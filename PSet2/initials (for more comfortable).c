/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet2: Initials (more comfortable)

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2017

**/

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // Andrey Tymofeiuk: Getting name from user
    string full_name = get_string();

    // Andrey Tymofeiuk: Making all the letters uppercase
    for (int i = 0, ceiling = strlen(full_name); i < ceiling; i++)
    {
        full_name[i] = toupper(full_name[i]);
    }

    // Andrey Tymofeiuk: Check for the 1st character
    if (full_name[0] != ' ')
        printf("%c", full_name[0]);
    // Andrey Tymofeiuk: Key loop to get the first letters from words
    for (int j = 0, ceiling = strlen(full_name); j < ceiling-2; j++)
    {
        if (full_name[j] == ' ')
        {
            int k = 0;
            while (full_name[k+j] == ' ')
                k++;
            if (full_name[k+j] != '\0')
                printf("%c", full_name[k+j]);
            j = j+k;
        }
    }
    printf("\n");
}