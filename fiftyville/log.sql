-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Finding description from crime scene reports of what happened
SELECT description FROM crime_scene_reports
WHERE day = '28' AND month = '7' AND year = '2021' AND street = 'Humphrey Street';

--get info from the 3 people interviewed
--1. theif got in car within 10 min of stealing (10:15-10:25)
--2. theif showed up at legget street at the atm earlier in the morning
--3. thief talk on phone with accomplish to buy ticket to leave fiftyvilles tommorrow (talk for less than 1 min on the phone)
SELECT * FROM interviews WHERE day = '28' AND month = '7' AND year = '2021';

--investigate first eyewitness evidence
SELECT * FROM bakery_security_logs
JOIN people ON people.license_plate = bakery_security_logs.license_plate
WHERE day = '28' AND month = '7' AND year = '2021' AND HOUR = '10';
--by joining the logs table to people table joining their license plate and picking the name of people who left in the time frame,i got 8 suspect.

--investigate second eyewitness
SELECT * FROM atm_transactions
JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number
JOIN people ON people.id = bank_accounts.person_id
WHERE atm_transactions.day = '28' AND atm_transactions.month = '7' AND atm_transactions.year = '2021' AND atm_location = 'Leggett Street';
--by joining the atm transaction to the bank account and further join to determine the person name who used the atm within the time frame, i got 9 more suspects.

--investigate third eyewitness
SELECT * FROM phone_calls
JOIN people ON people.phone_number = phone_calls.caller
WHERE day = '28' AND month = '7' AND year = '2021' AND duration < 60;
--by joining the phonecalls table to the people table using their phone number as a link and limiting the duration of the call to within 60 second, i was able to get 10 more suspect.

-- by cross referencing all the suspect in all 3 location where the eyewitness reported seeing, only diana and bruce appeared to fit all 3 suspect description.

--determine if its diana or bruce by determine who got on the earliest flight tommorrow
SELECT * FROM flights
JOIN airports ON airports.id = flights.origin_airport_id
JOIN passengers ON passengers.flight_id = flights.id
JOIN people ON people.passport_number = passengers.passport_number
WHERE people.name = 'Bruce';
--bruce left on the flight taking off on 7/29/2021 at 8:20

SELECT * FROM flights
JOIN airports ON airports.id = flights.origin_airport_id
JOIN passengers ON passengers.flight_id = flights.id
JOIN people ON people.passport_number = passengers.passport_number
WHERE people.name = 'Diana';
--Diana left on the flight taking off on 7/29/2021 at 16:00

--therefore it is bruce who was the thief

--determine where thief escaped to
SELECT * FROM flights
JOIN airports ON airports.id = flights.destination_airport_id
JOIN passengers ON passengers.flight_id = flights.id
JOIN people ON people.passport_number = passengers.passport_number
WHERE people.name = 'Bruce';
-- bruce landed in New York City

--determine who is the accomplice:
SELECT * FROM phone_calls
JOIN people ON people.phone_number = phone_calls.receiver
WHERE day = '28' AND month = '7' AND year = '2021' AND duration < 60 AND phone_calls.caller = (SELECT phone_number FROM people WHERE people.name = 'Bruce');
--by finding who own the phone number on the recieving end of the phone call, we can find who the accomplice is which in this case is Robin.



























--failed attempt due not somehow skipping bruce name when initially listing down suspect for 3rd witness

--determine where thief escaped to
SELECT * FROM airports
JOIN flights ON flights.destination_airport_id = airports.id
JOIN passengers ON passengers.flight_id = flights.id
JOIN people ON people.passport_number = passengers.passport_number
WHERE people.name = 'Diana';
-- Diana kept flying 3 time and ended up last landing in Dallas;

--determine who is the accomplish
SELECT * FROM phone_calls
JOIN people ON people.phone_number = phone_calls.receiver
WHERE day = '28' AND month = '7' AND year = '2021' AND phone_calls.caller = (SELECT phone_number FROM people WHERE people.name = 'Diana');
-- by working in reverse and find who the receiver of the call was, we were able to discover it was Phillip hence he is the accomplish
-- at this stage i was also a bit confused on whether the thief was phillip or diana since we dont have the information on whether the accomplish called or the thief called(although we can say diana is the thief because it would make more sense if its the thief calling after succeeding, you can never be too sure)
-- so by cross referencing phillip name to the 3 list of suspect provided by the eye witness, i was able to confirm that he is not the thief.