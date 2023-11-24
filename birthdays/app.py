import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        db.execute("INSERT INTO birthdays(name,day,month) VALUES (?,?,?);", request.form.get("name"), request.form.get("date"), request.form.get("month"))


        # TODO: Add the user's entry into the database

        return redirect("/")

    else:
        # TODO: Display the entries in the database on index.html
        name = db.execute("SELECT * FROM birthdays;")
        listname = []
        listdate= []
        listmonth= []
        for x in range(len(name)):
            listname.append(name[x]["name"])

        for y in range(len(name)):
            listdate.append(name[y]["day"])

        for z in range(len(name)):
            listmonth.append(name[z]["month"])

        return render_template("index.html", name=listname, day= listdate, month= listmonth)


