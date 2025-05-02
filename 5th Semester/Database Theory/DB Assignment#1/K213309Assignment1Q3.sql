----DB Assignment#1 K213309

--Q3
--Flights(flno: integer, from: string, to: string, distance: integer, departs: time, arrives: time, price: real)
CREATE TABLE Flights(flno INT PRIMARY KEY, from_ VARCHAR(255), to_ VARCHAR(255), Distance INT, Departs VARCHAR(255), Arrives VARCHAR(255), Price REAL);
DROP TABLE Flights;

--Aircraft(aid: integer, aname: string, cruisingrange: integer)
CREATE TABLE Aircraft(aid INT PRIMARY KEY, aname VARCHAR(255), CruisingRange INT);
DROP TABLE Aircraft;

--Certified(eid: integer, aid: integer)
CREATE TABLE Certified(eid INT , aid INT, FOREIGN KEY (aid) REFERENCES Aircraft(aid));
DROP TABLE Certified;

--Employees(eid: integer, ename: string, salary: integer)
CREATE TABLE Employees(eid INT PRIMARY KEY, ename VARCHAR(255), Salary INT);
ALTER TABLE Certified ADD FOREIGN KEY (eid) REFERENCES Employees(eid);
DROP TABLE Employees;

--Inserting Values
INSERT INTO Employees VALUES(3309, 'Mohammad Yehya', 100000);
INSERT INTO Employees VALUES(8543, 'AZB', 20000);
INSERT INTO Employees VALUES(9543, 'YCX', 110000);

INSERT INTO Aircraft VALUES(9033, 'MYH', 65411);
INSERT INTO Aircraft VALUES(1234, 'ABC', 84587);
INSERT INTO Aircraft VALUES(5678, 'DEF', 74152);
INSERT INTO Aircraft VALUES(4123, 'GHI', 85123);
INSERT INTO Aircraft VALUES(7412, 'Boeing', 35414);

INSERT INTO Certified VALUES(3309, 9033);
INSERT INTO Certified VALUES(3309, 1234);
INSERT INTO Certified VALUES(3309, 5678);
INSERT INTO Certified VALUES(3309, 4123);
INSERT INTO Certified VALUES(3309, 7412);

INSERT INTO Flights VALUES(12524, 'Los Angeles', 'Honolulu',  12312, '1000', '2200', 200000);
INSERT INTO Flights VALUES(45154, 'Los Angeles', 'Honolulu',  12312, '0600', '1800', 150000);
INSERT INTO Flights VALUES(95245, 'Los Angeles', 'Chicago', 75000, '2000', '0400', 10000);
INSERT INTO Flights VALUES(74859, 'Madison', 'Chicago', 4100, '1200', '1400', 1000);
INSERT INTO Flights VALUES(53468, 'Chicago', 'New York', 1200, '1430', '1530', 1500);
INSERT INTO Flights VALUES(56431, 'Madison', 'New York', 5300, '1000', '1400', 4000);

Truncate Table Flights;
--TASK 1 ~ Find the names of aircraft such that all pilots certified to operate them have salaries more than $80,000.
SELECT *
FROM Aircraft
WHERE aid = (
    SELECT aid
    FROM Certified
    WHERE eid = ANY(
        SELECT eid
        FROM Employees
        WHERE Salary > 80000));
        
--TASK 2 ~ For each pilot who is certified for more than three aircraft, find the e_id and the maximum cruising range of the aircraft for which she or he is certified.
SELECT eid, CruisingRange
FROM Employees, Aircraft
WHERE eid = ANY(
    SELECT eid
    FROM Certified
    GROUP BY eid
    HAVING COUNT(eid) > 3);
    
--TASK 3 ~ Find the names of pilots whose salary is less than the price of the cheapest route from Los Angeles to Honolulu.
SELECT *
FROM Employees
WHERE SALARY < ANY(
    SELECT MIN(Price)
    FROM Flights
    WHERE From_ = 'Los Angeles' AND to_ = 'Honolulu');

--TASK 4 ~ Find the names of pilots certified for some Boeing aircraft.
SELECT *
FROM Employees
WHERE eid = (
    SELECT eid
    FROM Certified
    WHERE aid = (
        SELECT aid
        FROM Aircraft
        WHERE aname = 'Boeing'));
        
--TASK 5 ~ Find the aids of all aircraft that can be used on routes from Los Angeles to Chicago.
SELECT *
FROM Aircraft
WHERE CruisingRange > ANY(
    SELECT Distance
    FROM Flights
    WHERE from_ = 'Los Angeles' AND to_ = 'Chicago');
    
--TASK 6 ~ Identify the routes that can be piloted by every pilot who makes more than $100,000.
--No Relation between Flights and Employee???
SELECT DISTINCT F.from_, F.to_
FROM Flights F
WHERE NOT EXISTS(
    SELECT *
    FROM Employees E
    WHERE E.salary > 100000
    AND NOT EXISTS(
        SELECT *
        FROM Aircraft A, Certified C
        WHERE A.cruisingrange > F.distance AND E.eid = C.eid AND A.aid = C.aid));

--TASK 7 ~ A customer wants to travel from Madison to New York with no more than two changes of flight. 
--List the choice of departure times from Madison if the customer wants to arrive in New York by 6 p.m.
SELECT *
FROM Flights 
WHERE flno = (
    SELECT flno
    FROM Flights
    WHERE from_ = 'Madison' AND to_ = 'New York' AND arrives < '1800')
OR  flno = (
    SELECT F0.flno
    FROM Flights F0, Flights F1
    WHERE F0.from_ = 'Madison' AND F0.to_ != 'New York' 
    AND F1.from_ = F0.to_ AND F1.to_ = 'New York' 
    AND F1.departs > F0.arrives AND F1.arrives < '1800')
OR  flno = (
    SELECT F0.flno
    FROM Flights F0, Flights F1, Flights F2
    WHERE F0.from_ = 'Madison' AND F0.to_ != 'New York'  
    AND F1.from_ = F0.to_ AND F1.to_ != 'New York' 
    AND F2.from_ = F1.to_ AND F2.to_ = 'New York'
    AND F1.departs > F0.arrives AND F2.departs > F1.arrives AND F2.arrives < '1800');



--TASK 8 ~ Compute the difference between the average salary of a pilot and the average salary of all employees (including pilots).
SELECT AVG(s1) - AVG(s2) AS Difference
FROM (
    SELECT e1.Salary AS s1, e2.Salary AS s2
    FROM Employees e1, Employees e2
    WHERE e1.eid = ANY(
        SELECT C.eid
        FROM Certified C));
        
--TASK 9 ~ Print the name and salary of every nonpilot whose salary is more than the average salary for pilots.
SELECT *
FROM Employees
WHERE eid NOT IN(
    SELECT eid
    FROM Certified)
AND Salary > ANY(
    SELECT AVG(Salary)
    FROM Employees
    WHERE eid = ANY(
        SELECT eid
        FROM Certified));

--TASK 10 ~ Print the names of employees who are certified only on aircrafts with cruising range longer than 1000 miles.
SELECT * 
FROM Employees
WHERE eid = ANY(
    SELECT eid
    FROM Certified
    WHERE aid = ANY(
        SELECT aid
        FROM Aircraft
        WHERE CruisingRange > 1000));
        
--TASK 11 ~ Print the names of employees who are certified only on aircrafts with cruising range longer than 1000 miles, but on at least two such aircrafts.
SELECT * 
FROM Employees
WHERE eid = ANY(
    SELECT eid
    FROM Certified
    WHERE aid = ANY(
        SELECT aid
        FROM Aircraft
        WHERE CruisingRange > 1000)
    GROUP BY eid
    HAVING COUNT(eid) >= 2);

--TASK 12 ~ Print the names of employees who are certified only on aircrafts with cruising range longer than 1000 miles and who are certified on some Boeing aircraft.
SELECT * 
FROM Employees
WHERE eid = ANY(
    SELECT eid
    FROM Certified
    WHERE aid = ANY(
        SELECT aid
        FROM Aircraft
        WHERE CruisingRange > 1000
        AND aname = 'Boeing'));