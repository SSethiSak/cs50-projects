import os
from cs50 import SQL

db = SQL("sqlite:///birthdays.db")
name = db.execute("SELECT * FROM birthdays;")

listdate = []
for x in range(len(name)):
    listdate.append(name[x]["day"])
print(listdate)