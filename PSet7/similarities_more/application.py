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

import cs50
import re
from flask import Flask, abort, redirect, render_template, request
from html import escape
from werkzeug.exceptions import default_exceptions, HTTPException

from helpers import distances, Operation

# Web app
app = Flask(__name__)


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
def index():
    """Handle requests for / via GET (and POST)"""
    return render_template("index.html")


@app.route("/score", methods=["POST"])
def score():
    """Handle requests for /score via POST"""

    # Read files
    s1 = request.form.get("string1")
    s2 = request.form.get("string2")
    if not s1 or not s2:
        abort(400, "missing strings")

    # Score files
    matrix = distances(s1, s2)

    # Extract operations from table
    operations = []
    i, j = len(s1), len(s2)
    while True:
        _, operation = matrix[i][j]
        if not operation:
            break
        if operation == Operation.INSERTED:
            j -= 1
        elif operation == Operation.DELETED:
            i -= 1
        else:
            i -= 1
            j -= 1
        operations.append(operation)
    operations.reverse()

    # Maintain list of intermediate strings, operation, and descriptions
    transitions = [(s1, None, None)]
    i = 0

    # Apply each operation
    prev = s1
    for operation in operations:

        # Update string and description of operation
        if operation == Operation.INSERTED:
            s = (prev[:i], s2[i], prev[i:])
            description = f"inserted '{s2[i]}'"
            prev = prev[:i] + s2[i] + prev[i:]
            i += 1
        elif operation == Operation.DELETED:
            s = (prev[:i], prev[i], prev[i + 1:])
            description = f"deleted '{prev[i]}'"
            prev = prev[:i] + prev[i + 1:]
        elif prev[i] != s2[i]:
            s = (prev[:i], s2[i], prev[i + 1:])
            description = f"substituted '{prev[i]}' with '{s2[i]}'"
            prev = prev[:i] + s2[i] + prev[i + 1:]
            i += 1
        else:
            i += 1
            continue
        transitions.append((s, str(operation), description))
    transitions.append((s2, None, None))

    # Output comparison
    return render_template("score.html", matrix=matrix, s1=s1, s2=s2, operations=transitions)


@app.errorhandler(HTTPException)
def errorhandler(error):
    """Handle errors"""
    return render_template("error.html", error=error), error.code


# https://github.com/pallets/flask/pull/2314
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
