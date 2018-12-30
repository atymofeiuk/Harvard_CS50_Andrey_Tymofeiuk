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

from flask import Flask, redirect, render_template, request, url_for

import helpers
import sys
import os
import nltk
from analyzer import Analyzer

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "")
    if not screen_name:
        return redirect(url_for("index"))

    # get screen_name's tweets
    tweets = helpers.get_user_timeline(screen_name)

    # absolute paths to lists
    positives = os.path.join(sys.path[0], "positive-words.txt")
    negatives = os.path.join(sys.path[0], "negative-words.txt")

    # instantiate analyzer
    analyzer = Analyzer(positives, negatives)

    tokenizer = nltk.tokenize.TweetTokenizer()

    # Andrey Tymofeiuk: This is implemented by me
    positive, negative, neutral = 0.0, 0.0, 0.0

    tweetsCounter = 0
    for tweet in tweets:
        if tweetsCounter == 100:
            break
        score = 0
        tokens = tokenizer.tokenize(tweet)
        for word in tokens:
            score += analyzer.analyze(word)
        if score > 0.0:
            positive += 1
        elif score < 0.0:
            negative += 1
        else:
            neutral += 1
        tweetsCounter += 1

    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
