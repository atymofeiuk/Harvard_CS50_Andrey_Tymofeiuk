'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Bleep

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2019

'''

# Andrey Tymofeiuk: Getting necessary libraries
from cs50 import get_string
import sys


def main():

    # Andrey Tymofeiuk: Checking correct input
    if len(sys.argv) != 2:
        print("Usage: python vigenere.py k")
        sys.exit(1)

    file_name = sys.argv[1]
    banned_words_list = []

    # Andrey Tymofeiuk: Opening the file
    f = open(file_name, "r")
    for line in f:
        banned_words_list.append(line.rstrip("\n"))

    # Andrey Tymofeiuk: Getting the message
    msg = get_string("What message would you like to censor?\n")

    # Andrey Tymofeiuk: Splitting the message and marking banned words by flag in flags_list
    msg_list = msg.split(" ")
    flags_list = []
    for word in msg_list:
        if word.lower() in banned_words_list:
            flags_list.append(True)
        else:
            flags_list.append(False)

    # Andrey Tymofeiuk: Constructing final message
    final_message = ""
    for idx in range(len(msg_list)):
        if flags_list[idx] == True:
            for letter in msg_list[idx]:
                final_message += "*"
        else:
            final_message += msg_list[idx]
        final_message += " "

    f.close()
    print(final_message)


if __name__ == "__main__":
    main()