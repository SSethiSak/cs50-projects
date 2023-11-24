import os

from cs50 import SQL

db = SQL("sqlite:///finance.db")

placeholder = "seth"
#listdict = db.execute("SELECT username FROM users WHERE username=?", placeholder)

   # namehold = [d.get('username') for d in listdict]
    #try:
   #     print(listdict[0]['username'])
   # except:
      #  print("new name")
id = db.execute("SELECT id FROM users WHERE username = ?",placeholder)
db.execute("INSERT INTO purchases (user_id, share, share_amount, buyprice) VALUES (?, 'E', '1', '42.67')", id[0]['id'])
           CREATE TABLE purchases(
               purchase_id INTEGER,
               user_id INTEGER,
               share TEXT,
               share_amount INTEGER,
               buyprice INTEGER,
               buytime TIMESTAMP,
               FOREIGN KEY (user_id) REFERENCES users(id),
               PRIMARY KEY (purchase_id)
               );