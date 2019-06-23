'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Credit (for "more comfortable")

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2019

'''

# Andrey Tymofeiuk: Getting necessary function from CS50 library
from cs50 import get_string

# Andrey Tymofeiuk: Getting correct input from the user
while True:
    input = get_string("Number: ")
    if input.isdigit():
        break

# Andrey Tymofeiuk: Luhn's algorithm for checking correctness
second_to_two_digits_list = []
for c1 in input[-2::-2]:
    second_to_two_digits_list.append(str(2 * int(c1)))
other_digits_list = []
for c2 in input[::-2]:
    other_digits_list.append(c2)

sum_digits_second_to_two = 0
sum_digits_other = 0

for number in second_to_two_digits_list:
    for digit in number:
        sum_digits_second_to_two += int(digit)
for digit in other_digits_list:
    sum_digits_other += int(digit)

total_sum = sum_digits_second_to_two + sum_digits_other

# Andrey Tymofeiuk: Checking whether it is a correct number and which type of cards does it belong
if total_sum % 10 == 0:
    if len(input) == 16 and input[0] == '5' and (input[1] == '1' or input[1] == '2' or input[1] == '3' or input[1] == '4' or input[1] == '5'):
        print("MASTERCARD")

    if (len(input) == 13 or len(input) == 16) and input[0] == '4':
        print("VISA")

    if len(input) == 15 and (input[0:2] == '34' or input[0:2] == '37'):
        print("AMEX")

else:
    print("INVALID")

