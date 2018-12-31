'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Similarities (for "less comfortable")

    NB: PSet6/Similarities files with Andrey Tymofeiuk's code are helpers.py and index.html,
    other additional files contain distribution code provided by Harvard CS50 staff

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

'''

from nltk.tokenize import sent_tokenize

# Andrey Tymofeiuk: Implemented by me
def lines(a, b):
    """Return lines in both a and b"""

    linesA = a.split("\n")
    linesB = b.split("\n")

    commonLines = []

    for element in linesA:
        if (element in linesB) and (element not in commonLines):
            commonLines.append(element)
    for element in linesB:
        if (element in linesA) and (element not in commonLines):
            commonLines.append(element)
    return commonLines

# Andrey Tymofeiuk: Implemented by me
def sentences(a, b):
    """Return sentences in both a and b"""

    sentencesA = sent_tokenize(a)
    sentencesB = sent_tokenize(b)

    commonSentences = []

    for element in sentencesA:
        if (element in sentencesB) and (element not in commonSentences):
            commonSentences.append(element)
    for element in sentencesB:
        if (element in sentencesA) and (element not in commonSentences):
            commonSentences.append(element)

    return commonSentences

# Andrey Tymofeiuk: Implemented by me
def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    subA = []
    subB = []
    common = []

    s = 0
    while (s + n) != (len(a) + 1):
        subA.append(a[s:s + n])
        s += 1

    s = 0
    while (s + n) != (len(b) + 1):
        subB.append(b[s:s + n])
        s += 1

    for el in subA:
        if (el in subB) and (el not in common):
            common.append(el)
    for el in subB:
        if (el in subA) and (el not in common):
            common.append(el)

    return common
