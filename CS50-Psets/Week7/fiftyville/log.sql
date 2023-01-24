-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Check the crime description of theft of CS50 duck.
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND year = 2021 AND street = "Humphrey Street";
-- 10:15am
-- ATM Leggett Street withdraw
-- earliest flight out of fiffyville tomorrow,
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
+-----+----------+---------------+
| id  | activity | license_plate |
+-----+----------+---------------+
| 260 | exit     | 5P2BI95       |
| 261 | exit     | 94KL13X       |
| 262 | exit     | 6P58WS2       |
| 263 | exit     | 4328GD8       |
| 264 | exit     | G412CB7       |
| 265 | exit     | L93JTIZ       |
| 266 | exit     | 322W7JE       |
| 267 | exit     | 0NTHK55       |
+-----+----------+---------------+
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
SELECT id, account_number, amount FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
+-----+----------------+--------+
| id  | account_number | amount |
+-----+----------------+--------+
| 246 | 28500762       | 48     |
| 264 | 28296815       | 20     |
| 266 | 76054385       | 60     |
| 267 | 49610011       | 50     |
| 269 | 16153065       | 80     |
| 275 | 86363979       | 10     |
| 288 | 25506511       | 20     |
| 313 | 81061156       | 30     |
| 336 | 26013199       | 35     |
+-----+----------------+--------+
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
SELECT id, caller, receiver FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60;
+-----+----------------+----------------+
| id  |     caller     |    receiver    |
+-----+----------------+----------------+
| 221 | (130) 555-0289 | (996) 555-8899 |
| 224 | (499) 555-9472 | (892) 555-8872 |
| 233 | (367) 555-5533 | (375) 555-8161 |
| 251 | (499) 555-9472 | (717) 555-1342 |
| 254 | (286) 555-6063 | (676) 555-6554 |
| 255 | (770) 555-1861 | (725) 555-3243 |
| 261 | (031) 555-6622 | (910) 555-3251 |
| 279 | (826) 555-1652 | (066) 555-9701 |
| 281 | (338) 555-6650 | (704) 555-2131 |
+-----+----------------+----------------+
SELECT id, destination_airport_id, hour, minute FROM flights WHERE month = 7 AND day = 29 AND year = 2021 ORDER BY hour ASC, minute ASC;
+----+------------------------+------+--------+
| id | destination_airport_id | hour | minute |
+----+------------------------+------+--------+
| 36 | 4                      | 8    | 20     |
| 43 | 1                      | 9    | 30     |
| 23 | 11                     | 12   | 15     |
| 53 | 9                      | 15   | 20     |
| 18 | 6                      | 16   | 0      |
+----+------------------------+------+--------+

SELECT abbreviation, full_name, city FROM airports WHERE id = 4;
+--------------+-------------------+---------------+
| abbreviation |     full_name     |     city      |
+--------------+-------------------+---------------+
| LGA          | LaGuardia Airport | New York City |
+--------------+-------------------+---------------+

SELECT person_id, creation_year FROM bank_accounts JOIN people ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw");
+-----------+---------------+
| person_id | creation_year |
+-----------+---------------+
| 686048    | 2010          |
| 514354    | 2012          |
| 458378    | 2012          |
| 395717    | 2014          |
| 396669    | 2014          |
| 467400    | 2014          |
| 449774    | 2015          |
| 438727    | 2018          |
+-----------+---------------+

SELECT * FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw");
+--------+---------+----------------+-----------------+---------------+----------------+-----------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate | account_number | person_id | creation_year |
+--------+---------+----------------+-----------------+---------------+----------------+-----------+---------------+
| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | 686048    | 2010          |
| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       | 26013199       | 514354    | 2012          |
| 458378 | Brooke  | (122) 555-4581 | 4408372428      | QX4YZN3       | 16153065       | 458378    | 2012          |
| 395717 | Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       | 28296815       | 395717    | 2014          |
| 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       | 25506511       | 396669    | 2014          |
| 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       | 28500762       | 467400    | 2014          |
| 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       | 76054385       | 449774    | 2015          |
| 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       | 81061156       | 438727    | 2018          |
+--------+---------+----------------+-----------------+---------------+----------------+-----------+---------------+

SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60 AND caller IN (SELECT phone_number FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"));
+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
| 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
| 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       |
| 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54       |
+-----+----------------+----------------+------+-------+-----+----------+

SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60 AND caller IN (SELECT phone_number FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")));
+--------+---------+----------------+-----------------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate |
+--------+---------+----------------+-----------------+---------------+
| 395717 | Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       |
| 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       |
| 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       |
| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+---------+----------------+-----------------+---------------+

SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2021 AND hour = 10 AND minute IN (15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25) AND license_plate IN (SELECT license_plate FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60 AND caller IN (SELECT phone_number FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"))));
+---------------+
| license_plate |
+---------------+
| 94KL13X       |
| 322W7JE       |
+---------------+

SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2021 AND hour = 10 AND minute IN (15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25) AND license_plate IN (SELECT license_plate FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60 AND caller IN (SELECT phone_number FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")))));
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 514354 | Diana | (770) 555-1861 | 3592750733      | 322W7JE       |
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+-------+----------------+-----------------+---------------+

SELECT * FROM passengers WHERE passport_number IN (SELECT passport_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2021 AND hour = 10 AND minute IN (15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25) AND license_plate IN (SELECT license_plate FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60 AND caller IN (SELECT phone_number FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"))))));
+-----------+-----------------+------+
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 18        | 3592750733      | 4C   |
| 24        | 3592750733      | 2C   |
| 36        | 5773159633      | 4A   |
| 54        | 3592750733      | 6C   |
+-----------+-----------------+------+

-- by checking the flight id Bruce booked the earliest flight for tomorrow to New York which leaves the only person that matches all the suspect descriptions.

SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 61 AND caller = "(367) 555-5533";
+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
+-----+----------------+----------------+------+-------+-----+----------+

-- He called his accomplice on the day he committed crime for less than a minute
SELECT * FROM people WHERE phone_number = "(375) 555-8161";
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 864400 | Robin | (375) 555-8161 |                 | 4V16VO0       |
+--------+-------+----------------+-----------------+---------------+