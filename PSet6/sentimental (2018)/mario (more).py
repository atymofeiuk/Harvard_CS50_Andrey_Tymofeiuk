'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Mario (for "more comfortable")

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

'''

from cs50 import get_int

h = -1
while (h < 0 or h > 23):
    h = get_int("Height: ")

for i in range(h):
    print((h - i - 1) * " ",  end='')
    print((i + 1) * "#", end='')
    print("  ", end='')
    print((i + 1) * "#", end='')
    print()