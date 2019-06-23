'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Cash (for "less comfortable")

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2019

'''

# Andrey Tymofeiuk: Getting necessary CS50 library
from cs50 import get_float


# Andrey Tymofeiuk: Requiring proper positive input from user
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

# Andrey Tymofeiuk: Converting float to integer
coins = round(change * 100)

# Andrey Tymofeiuk: Declaring coins counter
count_coins = 0

# Andrey Tymofeiuk: Counting quarters
q_count = coins // 25
coins -= q_count * 25

# Andrey Tymofeiuk: Counting dimes
d_count = coins // 10
coins -= d_count * 10

# Andrey Tymofeiuk: Counting nickels
n_count = coins // 5
coins -= n_count * 5

# Andrey Tymofeiuk: Counting pennies
p_count = coins // 1
coins -= p_count * 1

# Andrey Tymofeiuk: Summation
count_coins = q_count + d_count + n_count + p_count

print(count_coins)