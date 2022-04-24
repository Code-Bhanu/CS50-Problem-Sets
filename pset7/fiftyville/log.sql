-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Get the description from crime scene reports
SELECT description FROM crime_scene_reports
WHERE year = 2020 AND month = 7 AND day = 28
AND street = "Chamberlin Street" ;


--Get the transcript of the interviews
SELECT transcript,name  FROM interviews
WHERE year = 2020 AND month = 7 AND day = 28
AND transcript like "%courthouse%";

--Get names of people who exited the courthouse
SELECT name FROM courthouse_security_logs
JOIN people ON courthouse_security_logs.license_plate = people.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity ="exit";


--Get names of people who have withdrawn money
SELECT people.name FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw");

--Get names of passengers who left fiftyville early the next day
SELECT name from people
WHERE passport_number IN (SELECT passport_number FROM passengers
WHERE flight_id = (SELECT flights.id FROM flights
JOIN airports ON flights.destination_airport_id = airports.id
WHERE year = 2020 AND month = 7 AND day = 29
AND origin_airport_id = 8 ORDER BY hour,minute LIMIT 1));


--Get names of all callers who talked for less than a minute
SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60";

--Intersect all the queries to find the thief
SELECT name FROM courthouse_security_logs
JOIN people ON courthouse_security_logs.license_plate = people.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity ="exit"
INTERSECT
SELECT people.name FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw")
INTERSECT
SELECT name from people
WHERE passport_number IN (SELECT passport_number FROM passengers
WHERE flight_id = (SELECT flights.id FROM flights
JOIN airports ON flights.destination_airport_id = airports.id
WHERE year = 2020 AND month = 7 AND day = 29
AND origin_airport_id = 8 ORDER BY hour,minute LIMIT 1))
INTERSECT
SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60";

--City where the thief is leaving to
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights
WHERE day = "29" AND month = "7" AND year = "2020" ORDER BY hour, minute LIMIT 1);

--The accomplice
SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60"
AND caller = (SELECT phone_number FROM people WHERE name = "Ernest");