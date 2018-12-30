'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Vigenere (for "less comfortable")

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
    sys.exit(1)

key = sys.argv[1]
for letter in key:
    if not letter.isalpha():
        print("Error")
        sys.exit(1)

len_key = len(key)
key_index = 0
plaintext = input("plaintext: ")
ciphertext = ""

for letter in range(len(plaintext)):
    if plaintext[letter].isalpha():
        if plaintext[letter].isupper():
            if key[key_index].isupper():
                ciphertext += chr(65 + ((ord(plaintext[letter]) - 65) + (ord(key[key_index]) - 65)) % 26)
                key_index += 1
            else:
                ciphertext += chr(65 + ((ord(plaintext[letter]) - 65) + (ord(key[key_index]) - 97)) % 26)
                key_index += 1
        else:
            if key[key_index].isupper():
                ciphertext += chr(97 + ((ord(plaintext[letter]) - 97) + (ord(key[key_index]) - 65)) % 26)
                key_index += 1
            else:
                ciphertext += chr(97 + ((ord(plaintext[letter]) - 97) + (ord(key[key_index]) - 97)) % 26)
                key_index += 1
    else:
        ciphertext += plaintext[letter]
    if key_index == len_key:
        key_index = 0

print("ciphertext: " + ciphertext)