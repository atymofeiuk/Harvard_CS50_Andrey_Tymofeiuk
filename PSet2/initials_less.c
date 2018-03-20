/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet2: Initials (less comfortable)

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2017

**/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string phrase = get_string();
    printf("%c", toupper(phrase[0]));

    int ceiling = strlen(phrase);
    int j = 1;

    while (j < ceiling)
    {
        if (strncmp(&phrase[j-1], " ", 1) == 0)
            printf("%c", toupper(phrase[j]));
        j++;
    }
    printf("\n");
}