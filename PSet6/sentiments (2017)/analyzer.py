'''

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet6: Sentiments

    NB: PSet6/Sentiments files with Andrey Tymofeiuk's code are analyzer.py and application.py,
    other additional files contain distribution code provided by Harvard CS50 staff

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2017

'''

import nltk

class Analyzer():
    """Implements sentiment analysis."""

    # Andrey Tymofeiuk: Method __init__ is implemented by me
    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        self.positives = positives
        self.negatives = negatives

    # Andrey Tymofeiuk: Method analyze is implemented by me
    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        positives = []
        negatives = []
        result = 0

        with open(self.positives) as lines:
            for line in lines:
                if line.startswith(";") == False and line.startswith(" ") == False:
                    positives.append(line.strip())

        with open(self.negatives) as lines:
            for line in lines:
                if line.startswith(";") == False and line.startswith(" ") == False:
                    negatives.append(line.strip())

        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)

        for word in tokens:
            if word.lower() in positives:
                result += 1
            if word.lower() in negatives:
                result -= 1

        return result