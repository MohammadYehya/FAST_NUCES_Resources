/* Create the schema for our tables */
CREATE TABLE Person(name varchar(255), age int, gender varchar(255));
CREATE TABLE Frequents(name varchar(255), pizzeria varchar(255));
CREATE TABLE Eats(name varchar(255), pizza varchar(255));
CREATE TABLE Serves(pizzeria varchar(255), pizza varchar(255), price number);

/* Populate the tables with our data */
INSERT INTO Person VALUES('Amy', 16, 'female');
INSERT INTO Person VALUES('Ben', 21, 'male');
INSERT INTO Person VALUES('Cal', 33, 'male');
INSERT INTO Person VALUES('Dan', 13, 'male');
INSERT INTO Person VALUES('Eli', 45, 'male');
INSERT INTO Person VALUES('Fay', 21, 'female');
INSERT INTO Person VALUES('Gus', 24, 'male');
INSERT INTO Person VALUES('Hil', 30, 'female');
INSERT INTO Person VALUES('Ian', 18, 'male');

INSERT INTO Frequents VALUES('Amy', 'Pizza Hut');
INSERT INTO Frequents VALUES('Ben', 'Pizza Hut');
INSERT INTO Frequents VALUES('Ben', 'Chicago Pizza');
INSERT INTO Frequents VALUES('Cal', 'Straw Hat');
INSERT INTO Frequents VALUES('Cal', 'New York Pizza');
INSERT INTO Frequents VALUES('Dan', 'Straw Hat');
INSERT INTO Frequents VALUES('Dan', 'New York Pizza');
INSERT INTO Frequents VALUES('Eli', 'Straw Hat');
INSERT INTO Frequents VALUES('Eli', 'Chicago Pizza');
INSERT INTO Frequents VALUES('Fay', 'Dominos');
INSERT INTO Frequents VALUES('Fay', 'Little Caesars');
INSERT INTO Frequents VALUES('Gus', 'Chicago Pizza');
INSERT INTO Frequents VALUES('Gus', 'Pizza Hut');
INSERT INTO Frequents VALUES('Hil', 'Dominos');
INSERT INTO Frequents VALUES('Hil', 'Straw Hat');
INSERT INTO Frequents VALUES('Hil', 'Pizza Hut');
INSERT INTO Frequents VALUES('Ian', 'New York Pizza');
INSERT INTO Frequents VALUES('Ian', 'Straw Hat');
INSERT INTO Frequents VALUES('Ian', 'Dominos');

INSERT INTO Eats VALUES('Amy', 'pepperoni');
INSERT INTO Eats VALUES('Amy', 'mushroom');
INSERT INTO Eats VALUES('Ben', 'pepperoni');
INSERT INTO Eats VALUES('Ben', 'cheese');
INSERT INTO Eats VALUES('Cal', 'supreme');
INSERT INTO Eats VALUES('Dan', 'pepperoni');
INSERT INTO Eats VALUES('Dan', 'cheese');
INSERT INTO Eats VALUES('Dan', 'sausage');
INSERT INTO Eats VALUES('Dan', 'supreme');
INSERT INTO Eats VALUES('Dan', 'mushroom');
INSERT INTO Eats VALUES('Eli', 'supreme');
INSERT INTO Eats VALUES('Eli', 'cheese');
INSERT INTO Eats VALUES('Fay', 'mushroom');
INSERT INTO Eats VALUES('Gus', 'mushroom');
INSERT INTO Eats VALUES('Gus', 'supreme');
INSERT INTO Eats VALUES('Gus', 'cheese');
INSERT INTO Eats VALUES('Hil', 'supreme');
INSERT INTO Eats VALUES('Hil', 'cheese');
INSERT INTO Eats VALUES('Ian', 'supreme');
INSERT INTO Eats VALUES('Ian', 'pepperoni');

INSERT INTO Serves VALUES('Pizza Hut', 'pepperoni', 12);
INSERT INTO Serves VALUES('Pizza Hut', 'sausage', 12);
INSERT INTO Serves VALUES('Pizza Hut', 'cheese', 9);
INSERT INTO Serves VALUES('Pizza Hut', 'supreme', 12);
INSERT INTO Serves VALUES('Little Caesars', 'pepperoni', 9.75);
INSERT INTO Serves VALUES('Little Caesars', 'sausage', 9.5);
INSERT INTO Serves VALUES('Little Caesars', 'cheese', 7);
INSERT INTO Serves VALUES('Little Caesars', 'mushroom', 9.25);
INSERT INTO Serves VALUES('Dominos', 'cheese', 9.75);
INSERT INTO Serves VALUES('Dominos', 'mushroom', 11);
INSERT INTO Serves VALUES('Straw Hat', 'pepperoni', 8);
INSERT INTO Serves VALUES('Straw Hat', 'cheese', 9.25);
INSERT INTO Serves VALUES('Straw Hat', 'sausage', 9.75);
INSERT INTO Serves VALUES('New York Pizza', 'pepperoni', 8);
INSERT INTO Serves VALUES('New York Pizza', 'cheese', 7);
INSERT INTO Serves VALUES('New York Pizza', 'supreme', 8.5);
INSERT INTO Serves VALUES('Chicago Pizza', 'cheese', 7.75);
INSERT INTO Serves VALUES('Chicago Pizza', 'supreme', 8.5);


--------------

--1 -- All pizzerias frequented by at least one person under the age of 18.
SELECT DISTINCT F.PIZZERIA
FROM FREQUENTS F JOIN PERSON P
ON F.NAME = P.NAME
WHERE P.AGE < 18;

--2 -- The names of all females who eat either mushroom or pepperoni pizza (or both).
SELECT DISTINCT P.NAME
FROM PERSON P JOIN EATS E
ON P.NAME = E.NAME
WHERE P.GENDER = 'female'
AND (E.PIZZA = 'mushroom' OR E.PIZZA = 'pepperoni');

--3 -- All pizzerias that serve at least one pizza that Amy eats for less than $10.
SELECT DISTINCT S.pizzeria
FROM EATS E JOIN SERVES S
ON E.PIZZA = S.PIZZA
WHERE E.NAME = 'Amy'
AND S.PRICE < 10;

--4 --The names of people who eat some pizza in a pizzeria they do not frequent.
(SELECT DISTINCT P.NAME
FROM PERSON P)
MINUS
(SELECT DISTINCT NAME
FROM 
((SELECT DISTINCT *
FROM FREQUENTS F)
MINUS
(SELECT DISTINCT E.NAME, S.PIZZERIA
FROM EATS E JOIN SERVES S
ON E.PIZZA = S.PIZZA)));

--5 --The names of people who eat some pizza only in the pizzeria they frequent.
(SELECT DISTINCT P.NAME
FROM PERSON P)
MINUS
(SELECT DISTINCT NAME
FROM 
((SELECT DISTINCT E.NAME, S.PIZZERIA
FROM EATS E JOIN SERVES S
ON E.PIZZA = S.PIZZA)
MINUS
(SELECT DISTINCT *
FROM FREQUENTS F)));