'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Cash (for "less comfortable")

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

'''

from cs50 import get_float

# Andrey Tymofeiuk: Checking for positive value
while True:
    given = get_float("Change owed: ") * 100
    if given >= 0:
        break

money = int(round(given, 2))

quarters = 0
while money >= 25:
    money -= 25
    quarters += 1

dimes = 0
while money >= 10:
    money -= 10
    dimes += 1

nickels = 0
while money >= 5:
    money -= 5
    nickels += 1

cents = 0
while money > 0:
    money -= 1
    cents += 1

coins = quarters + dimes + nickels + cents

print("{}".format(coins))