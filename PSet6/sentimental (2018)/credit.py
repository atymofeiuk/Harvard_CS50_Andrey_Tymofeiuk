'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Credit (for "more comfortable")

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

'''

from cs50 import get_string

# Andrey Tymofeiuk: Checking for the integer value
while True:
    card = get_string("Enter card number: ")
    try:
        if isinstance(int(card), int):
            break
    except ValueError:
        pass

card_len = len(card)

sec_digits_twice = []
other_digits = []
sec_digits_sum = 0

for i in range(len(card) - 1)[::-2]:
    sec_digits_twice.append(str(2 * int(card[i])))
    other_digits.append(card[i + 1])
if len(card) % 2 != 0:
    other_digits.append(card[0])

for element in sec_digits_twice:
    if len(element) != 1:
        sec_digits_sum += int(element[0]) + int(element[1])
    else:
        sec_digits_sum += int(element)

sum_other_digits = 0
for digit in other_digits:
    sum_other_digits += int(digit)

sum_final = sum_other_digits + sec_digits_sum

if (sum_final % 10 != 0) or (len(card) != 13 and len(card) != 14 and len(card) != 15 and len(card) != 16):
    print("INVALID")
elif card[0:2] == '34' or card[0:2] == '37':
    print("AMEX")
elif card[0] == '4':
    print("VISA")
elif card[0:2] == '51' or card[0:2] == '52' or card[0:2] == '53' or card[0:2] == '54' or card[0:2] == '55':
    print("MASTERCARD")