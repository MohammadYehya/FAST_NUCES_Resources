--DB Assignment#1 K213309

--Q4
--Emp(eid: integer, ename: string, age: integer, salary: real)
CREATE TABLE Emp (eid NUMBER PRIMARY KEY, ename VARCHAR(255), age NUMBER, Salary REAL);

--Dept(did: integer, budget: real, managerid: integer)
CREATE TABLE Dept (did NUMBER PRIMARY KEY, budget REAL, managerid NUMBER, FOREIGN KEY (managerid) REFERENCES Emp(eid) ON DELETE SET NULL);

--Works(eid: integer, did: integer, pct time: integer)
CREATE TABLE Work(eid NUMBER , did NUMBER, pcttime NUMBER, FOREIGN KEY (eid) REFERENCES Emp(eid) ON DELETE CASCADE, FOREIGN KEY (did) REFERENCES Dept(did) ON DELETE CASCADE);

--TASK 1 ~ Define a table constraint on Emp that will ensure that every employee makes at least $10,000.
ALTER TABLE Emp 
ADD CHECK (Salary > 10000);

--TASK 2 (REMOVED)~ Define a table constraint on Dept that will ensure that all managers have age > 30.
   
--TASK 3 (REMOVED)~ Define an assertion on Dept that will ensure that all managers have age &gt; 30. 
--Compare this assertion with the equivalent table constraint. Explain which is better.

--TASK 4 ~ Write SQL statements to delete all information about employees whose salaries exceed that of the manager of one or more departments that they work in. 
--Be sure to ensure that all the relevant integrity constraints are satisfied after your Updates.
DELETE
FROM Emp E
WHERE E.eid = (
    SELECT W.eid
    FROM Work W, Emp E2, Dept D
    WHERE W.did = D.did
    AND D.managerid = E2.eid
    AND E.salary > E2.salary);