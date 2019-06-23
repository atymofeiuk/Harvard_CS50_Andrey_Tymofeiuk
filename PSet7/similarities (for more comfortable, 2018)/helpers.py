'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Similarities (for "more comfortable")

    NB: PSet6/Similarities files with Andrey Tymofeiuk's code are helpers.py, matrix.html and index.html,
    other additional files contain distribution code provided by Harvard CS50 staff

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

'''

from enum import Enum

class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())

# Andrey Tymofeiuk: Implemented by me
def distances(a, b):
    """Calculate edit distance from a to b"""

    matrix = [[(0, 0) for x in range(len(b) + 1)] for y in range(len(a) + 1)]
    for z1 in range(len(b) + 1):
        matrix[0][z1] = (z1, Operation.INSERTED)
    for z2 in range(len(a) + 1):
        matrix[z2][0] = (z2, Operation.DELETED)
    matrix[0][0] = (0, None)

    for i in range(1, len(a) + 1):
        for j in range(1, len(b) + 1):
            cost_d = (matrix[i - 1][j][0] + 1, Operation.DELETED)
            cost_i = (matrix[i][j - 1][0] + 1, Operation.INSERTED)
            if a[i - 1] == b[j - 1]:
                cost_s = (matrix[i - 1][j - 1][0], Operation.SUBSTITUTED)
            else:
                cost_s = (matrix[i - 1][j - 1][0] + 1, Operation.SUBSTITUTED)

            collection = [cost_d, cost_i, cost_s]
            compare = [cost_d[0], cost_i[0], cost_s[0]]
            indexMin = compare.index(min(compare))

            matrix[i][j] = (collection[indexMin][0], collection[indexMin][1])

    return matrix
