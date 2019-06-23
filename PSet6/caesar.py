'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Caesar (for "less comfortable")

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2019

'''

# Andrey Tymofeiuk: Getting necessary libraries
import sys
from cs50 import get_string

# Andrey Tymofeiuk: Checking for proper usage
if len(sys.argv) != 2 or sys.argv[1].isdigit() == False:
    sys.exit(1)

# Andrey Tymofeiuk: Casting given code to integer
key = int(sys.argv[1])

# Andrey Tymofeiuk: Getting the word to cipher
word = get_string("plaintext: ")

# Andrey Tymofeiuk: Main for loop with Caesar algorithm
new_word = ""
for letter in word:
    if not letter.isalpha():
        new_word += letter
    elif letter.isupper():
        new_word += chr((65 + (ord(letter) + key - 65) % 26))
    else:
        new_word += chr((97 + (ord(letter) + key - 97) % 26))

print("ciphertext: " + new_word)
