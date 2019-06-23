'''
    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet7: Similarities (for "less comfortable")

    NB: PSet7/Similarities files with Andrey Tymofeiuk's code are helpers.py and index.html,
    other additional files contain distribution code provided by Harvard CS50 staff

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2019

'''

# Andrey Tymofeiuk: Getting necessary function from nltk library
from nltk.tokenize import sent_tokenize

# Andrey Tymofeiuk: Written by me
def lines(a, b):
    """Return lines in both a and b"""

    aList = a.split("\n")
    bList = b.split("\n")
    linesSimilar = []

    for line in aList:
        if line in bList and line not in linesSimilar:
            linesSimilar.append(line)

    return linesSimilar

# Andrey Tymofeiuk: Written by me
def sentences(a, b):
    """Return sentences in both a and b"""

    aSentences = sent_tokenize(a)
    bSentences = sent_tokenize(b)
    commonSentences = []

    for sentence in aSentences:
        if sentence in bSentences and sentence not in commonSentences:
            commonSentences.append(sentence)
    return commonSentences

# Andrey Tymofeiuk: Written by me
def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    aSubstrings = []
    i = 0
    j = n
    while j != (len(a) + 1):
        aSubstrings.append(a[i:j])
        i += 1
        j += 1

    bSubstrings = []
    i = 0
    j = n
    while j != (len(b) + 1):
        bSubstrings.append(b[i:j])
        i += 1
        j += 1

    commonSubstrings = []
    for substring in aSubstrings:
        if substring in bSubstrings and substring not in commonSubstrings:
            commonSubstrings.append(substring)

    return commonSubstrings
