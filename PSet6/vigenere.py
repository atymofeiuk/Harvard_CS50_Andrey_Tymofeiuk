'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Vigenere (for "more comfortable")

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
if len(sys.argv) != 2 or not sys.argv[1].isalpha():
    print("Usage: python vigenere.py k")
    sys.exit(1)

# Andrey Tymofeiuk: Getting given code
key = sys.argv[1]

# Andrey Tymofeiuk: Getting the word to cipher
word = get_string("plaintext: ")

# Andrey Tymofeiuk: Vigenere cipher
new_word = ""
key_c = 0
for letter in word:
    if key_c == len(key):
        key_c = 0
    if not letter.isalpha():
        new_word += letter
    elif letter.isupper():
        if key[key_c].isupper():
            new_word += chr((65 + (ord(letter) + ord(key[key_c]) - 65 - 65) % 26))
            key_c += 1
        else:
            new_word += chr((65 + (ord(letter) + ord(key[key_c]) - 65 - 97) % 26))
            key_c += 1
    else:
        if key[key_c].isupper():
            new_word += chr((97 + (ord(letter) + ord(key[key_c]) - 97 - 65) % 26))
            key_c += 1
        else:
            new_word += chr((97 + (ord(letter) + ord(key[key_c]) - 97 - 97) % 26))
            key_c += 1

print("ciphertext: " + new_word)
