'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Crack (for "more comfortable")

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2019

'''

# Andrey Tymofeiuk: Getting necessary libraries
import crypt
import sys
from cs50 import get_string

# Andrey Tymofeiuk: Checking for proper usage
if len(sys.argv) != 2:
    print("Usage: python crack.py hash")
    sys.exit(1)

user_input = sys.argv[1]
given_salt = sys.argv[1][0:2]
given_hash = sys.argv[1][2:]

guess = ""
# Andrey Tymofeiuk: Suppose answer has one letter
for idx in range(65, 123):
    guess += chr(idx)
    if user_input == crypt.crypt(guess, given_salt):
        print(guess)
        sys.exit(0)
    guess = guess[:-1]

# Andrey Tymofeiuk: Suppose answer has two letters
for idx in range(65, 123):
    guess += chr(idx)
    for idx2 in range(65, 123):
        guess += chr(idx2)
        if user_input == crypt.crypt(guess, given_salt):
            print(guess)
            sys.exit(0)
        guess = guess[:-1]
    guess = guess[:-1]

# Andrey Tymofeiuk: Suppose answer has three letters
for idx in range(65, 123):
    guess += chr(idx)
    for idx2 in range(65, 123):
        guess += chr(idx2)
        for idx3 in range(65, 123):
            guess += chr(idx3)
            if user_input == crypt.crypt(guess, given_salt):
                print(guess)
                sys.exit(0)
            guess = guess[:-1]
        guess = guess[:-1]
    guess = guess[:-1]

# Andrey Tymofeiuk: Suppose answer has four letters
for idx in range(65, 123):
    guess += chr(idx)
    for idx2 in range(65, 123):
        guess += chr(idx2)
        for idx3 in range(65, 123):
            guess += chr(idx3)
            for idx4 in range(65, 123):
                guess += chr(idx4)
                if user_input == crypt.crypt(guess, given_salt):
                    print(guess)
                    sys.exit(0)
                guess = guess[:-1]
            guess = guess[:-1]
        guess = guess[:-1]
    guess = guess[:-1]

# Andrey Tymofeiuk: Suppose answer has five letters
for idx in range(65, 123):
    guess += chr(idx)
    for idx2 in range(65, 123):
        guess += chr(idx2)
        for idx3 in range(65, 123):
            guess += chr(idx3)
            for idx4 in range(65, 123):
                guess += chr(idx4)
                for idx5 in range(65, 123):
                    guess += chr(idx5)
                    if user_input == crypt.crypt(guess, given_salt):
                        print(guess)
                        sys.exit(0)
                    guess = guess[:-1]
                guess = guess[:-1]
            guess = guess[:-1]
        guess = guess[:-1]
    guess = guess[:-1]

print("Some mistake")