/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet1: Credit ("hacker edition"/"for more comfortable" problem)

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

**/

#include <stdio.h>
#include <cs50.h>

#define ASCII_DIFFERENCE 48
#define MAX_LENGTH_OF_NUMBER 16

int main(void)
{
    // Andrey Tymofeiuk: Taking correct card number from the user as string
    long long input = get_long_long("Enter card number: ");
    char input_str[16];
    sprintf(input_str, "%lld", input);

    int len_str = 0;
    int checker = 0;
    while (input_str[checker] != '\0')
    {
        len_str++;
        checker++;
    }

    int int_digits_multiplied_by_two[MAX_LENGTH_OF_NUMBER/2];
    int other_digits[MAX_LENGTH_OF_NUMBER/2];
    int forward_counter = 0;
    int other_counter = 0;
    int backward_counter = len_str-2;

    // Andrey Tymofeiuk: General loop to get even and odd digits
    while (backward_counter > -1)
    {
        int_digits_multiplied_by_two[forward_counter] = ((int) input_str[backward_counter]-ASCII_DIFFERENCE)*2;
        other_digits[forward_counter] = ((int) input_str[backward_counter+1]-ASCII_DIFFERENCE);
        forward_counter++;
        if (backward_counter == 1)
        {
            other_digits[forward_counter] = ((int) input_str[backward_counter-1]-ASCII_DIFFERENCE);
            other_counter = forward_counter + 1;
            break;
        }
        backward_counter = backward_counter - 2;
        other_counter = forward_counter;
    }

    int sum_one = 0;
    for (int i = 0; i < forward_counter; i++)
    {
        if (int_digits_multiplied_by_two[i] < 10)
            sum_one = sum_one + int_digits_multiplied_by_two[i];
        else
            sum_one = sum_one + 1 + (int_digits_multiplied_by_two[i]-10);
    }


    int sum_two = 0;
    for (int i = 0; i < other_counter; i++)
    {
        sum_two = sum_two + other_digits[i];
    }

    // Andrey Tymofeiuk: Putting everything together
    int final_sum = sum_one + sum_two;

    // Andrey Tymofeiuk: Determining what card it is
    if ((final_sum % 10 == 0) && (input_str[0] == '3' && ((input_str[1] == '4') || (input_str[1] == '7')) && len_str == 15))
    {
        printf("AMEX\n");
    }

    else if ((final_sum % 10 == 0) && ((input_str[0] == '5' && ((input_str[1] == '1') || (input_str[1] == '2') || (input_str[1] == '3') || (input_str[1] == '4') || (input_str[1] == '5')) && len_str == 16)))
    {
        printf("MASTERCARD\n");
    }

    else if ((final_sum % 10 == 0) && (input_str[0] == '4' && ((len_str == 13) || (len_str == 16))))
    {
        printf("VISA\n");
    }

    else
        printf("INVALID\n");
}