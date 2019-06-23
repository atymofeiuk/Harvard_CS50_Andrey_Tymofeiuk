'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Mario (for "more comfortable")

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2019

'''

from cs50 import get_int

h = 0
while h < 1 or h > 23:
    h = get_int("Height: ")

for i in range(1, h + 1):

    for j in range(h - i):
        print(" ", end='')

    for l in range(i):
        print("#", end='')

    print("  ", end='')

    for l in range(i):
        print("#", end='')

    print("")

