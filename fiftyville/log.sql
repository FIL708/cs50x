-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Search for crime description, which took place on July 28, 2021 and that it took place on Humphrey Street.
SELECT *
    FROM crime_scene_reports
 WHERE year = 2021
     AND month = 7
     AND day = 28
     AND street = 'Humphrey Street'
     AND description LIKE '%CS50%';


-- Search for all 3 interviews in on 28 July 2021, where we could find mentions about bakery
SELECT transcript
    FROM interviews
 WHERE year = 2021
     AND month = 7
     AND day = 28
     AND transcript LIKE '%bakery%';

-- Search for license plate all cars that left parking 5 - 15 minutes after crime using hint from first interview.
SELECT license_plate
    FROM bakery_security_logs
 WHERE year = 2021
     AND month = 7
     AND day = 28
     AND hour = 10
     AND minute >= 15
     AND minute <= 25;


-- Search for (account_number) withdraw transaction on Lagget Street using hint from second interview.
SELECT account_number
    FROM atm_transactions
 WHERE year = 2021
    AND month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw';

-- Search for phone numers where caller talk less then 1 minute
SELECT caller
    FROM phone_calls
    WHERE year = 2021
        AND month = 7
        AND day = 28
        AND duration <= 60;

-- Find flight
SELECT flights.id
    FROM flights
    JOIN airports
    ON airports.id = flights.origin_airport_id
 WHERE flights.year = 2021
    AND flights.month = 7
    AND flights.day = 29
    AND airports.city = 'Fiftyville'
 ORDER BY flights.hour, flights.minute
 LIMIT 1;

-- Find all passengers (passport_number) on first airplane on 29 July 2021
SELECT passport_number
    FROM passengers
WHERE flight_id = 36;


-- FIND THIEF USING ALL ABOVE DATASET (BRUCE)
SELECT people.name
    FROM people
    JOIN bank_accounts
    ON people.id = bank_accounts.person_id
 WHERE people.license_plate
     IN (SELECT license_plate
            FROM bakery_security_logs
        WHERE year = 2021
            AND month = 7
            AND day = 28
            AND hour = 10
            AND minute >= 15
            AND minute <= 25)
     AND bank_accounts.account_number
        IN (SELECT account_number
                FROM atm_transactions
            WHERE year = 2021
                AND month = 7
                AND day = 28
                AND atm_location = 'Leggett Street'
                AND transaction_type = 'withdraw')
     AND people.phone_number
        IN (SELECT caller
                FROM phone_calls
             WHERE year = 2021
                AND month = 7
                AND day = 28
                AND duration <= 60)
     AND people.passport_number
        IN (SELECT passport_number
                FROM passengers
            WHERE flight_id = 36);






-- FIND ACCOMPLICE KNOWING BRUCE IS A KILLER (ROBIN)
SELECT name
    FROM people
 WHERE phone_number = (SELECT receiver
                        FROM phone_calls
                        WHERE year = 2021
                            AND month = 7
                            AND day = 28
                            AND duration <= 60
                            AND caller = (SELECT phone_number
                                            FROM people
                                        WHERE name = 'Bruce'));


-- FIND THE CITY THE THIEF ESCAPED TO:
SELECT city
    FROM flights
    JOIN airports
    ON airports.id = destination_airport_id
  WHERE flights.id = (SELECT flights.id
                        FROM flights
                        JOIN airports
                        ON airports.id = flights.origin_airport_id
                      WHERE flights.year = 2021
                        AND flights.month = 7
                        AND flights.day = 29
                        AND airports.city = 'Fiftyville'
                      ORDER BY flights.hour, flights.minute
                      LIMIT 1);
