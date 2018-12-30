'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Caesar (for "less comfortable")

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

'''

import sys
from cs50 import get_string

while len(sys.argv) != 2:
    print("Error")
    break

key = int(sys.argv[1])
plaintext = input("plaintext: ")
ciphertext = ""

for letter in range(len(plaintext)):
    if plaintext[letter].isalpha():
        if plaintext[letter].isupper():
            ciphertext += chr(65 + ((ord(plaintext[letter]) - 65 + key) % 26))
        else:
            ciphertext += chr(97 + ((ord(plaintext[letter]) - 97 + key) % 26))
    else:
        ciphertext += plaintext[letter]

print("ciphertext: " + ciphertext)