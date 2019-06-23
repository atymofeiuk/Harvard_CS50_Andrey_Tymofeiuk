'''
    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet7: Survey

    NB: PSet7/Survey files with Andrey Tymofeiuk's code are application.py, form.html and sheet.html,
    other additional files contain distribution code provided by Harvard CS50 staff

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2019

'''

import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")

# Andrey Tymofeiuk: Written by me
@app.route("/form", methods=["POST"])
def post_form():
    if not request.form.get("position"):
        return render_template("error.html", message = "You must specify your position")
    file = open("survey.csv", "a")
    writer = csv.writer(file)
    writer.writerow((request.form.get("name"), request.form.get("house"), request.form.get("position")))
    file.close()
    return redirect("/sheet")

# Andrey Tymofeiuk: Written by me
@app.route("/sheet", methods=["GET", "POST"])
def get_sheet():
    with open("survey.csv", "r") as file:
        reader = csv.reader(file)
        students = list(reader)
    return render_template("sheet.html", students=students)
