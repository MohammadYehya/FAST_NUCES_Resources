CREATE TABLE testing
(
    u_id number PRIMARY KEY,
    name varchar(255),
    price number
);

INSERT INTO testing VALUES(1, 'Yehya', 1500);
COMMIT;
ROLLBACK;

SELECT * FROM testing;


--Task 1 - Create table persons having personID as primary key, FirstName,LastName,Address,City and age as attributes.
--Update the record on personID=7 where FirstName=Erum and After the update it should be FirstName=Rida.
--Now Rollback the transaction to savepoint1 and see the changes.
CREATE TABLE Persons
(
    personID number PRIMARY KEY,
    FirstName varchar(255),
    LastName varchar(255),
    Address varchar(255),
    City varchar(255),
    age number
);
INSERT INTO Persons VALUES(1, 'a', 'e', 'abc', 'def', 18);
INSERT INTO Persons VALUES(2, 'b', 'f', 'def', 'ghi', 19);
INSERT INTO Persons VALUES(3, 'c', 'g', 'ghi', 'jkl', 21);
INSERT INTO Persons VALUES(4, 'd', 'h', 'jkl', 'mno', 22);
INSERT INTO Persons VALUES(5, 'e', 'i', 'mno', 'pqr', 20);

SAVEPOINT after_5;

INSERT INTO Persons VALUES(6, 'f', 'j', 'pqr', 'stf', 22);
INSERT INTO Persons VALUES(7, 'Erum', 'k', 'stu', 'vwx', 23);
INSERT INTO Persons VALUES(8, 'h', 'l', 'vwx', 'yza', 17);
INSERT INTO Persons VALUES(9, 'i', 'm', 'yza', 'bcd', 15);
INSERT INTO Persons VALUES(10, 'j', 'n', 'bcd', 'efg', 3);
UPDATE Persons SET FirstName = 'Rida' WHERE personID = 7;

SELECT * FROM Persons;
ROLLBACK TO SAVEPOINT after_5;
COMMIT;

--Task 2 - By using above persons table update a record on personID=8 and
--change the age from 28 to 30 then without commiting change create a new session and 
--update the record on PersonID=8 and set age=31.
--State what is the reason behind no update.


--Done in unshared region

SELECT * FROM Persons;


--Task 3 - Create another table named cars and create a 1-to-many from person to cars.
--Now insert some valid values into cars as well. 
--Add a savepoint after every insertion and don’t commit any of the changes yet.
CREATE TABLE Cars
(
    carID number PRIMARY KEY,
    cname varchar(255),
    personID number,
    FOREIGN KEY (personID) REFERENCES Persons(PersonID)
);
set serveroutput on;
SELECT * FROM Cars;
TRUNCATE TABLE Cars;
DECLARE
    countcar number;
BEGIN
    INSERT INTO Cars VALUES(1,'a', 1);      --Insert car 1 to Person 1 -> Allowed
    SAVEPOINT c1;
    INSERT INTO Cars VALUES(2,'b', 1);      --Insert car 2 to Person 1 -> Allowed
    SELECT count(*) INTO countcar FROM Cars WHERE PersonID = 1 GROUP BY PersonID;
    IF(countcar > 3) THEN ROLLBACK TO SAVEPOINT c1; END IF;
    SAVEPOINT c2;
    INSERT INTO Cars VALUES(3,'c', 1);      --Insert car 3 to Person 1 -> Allowed
    SELECT count(*) INTO countcar FROM Cars WHERE PersonID = 1 GROUP BY PersonID;
    IF(countcar > 3) THEN ROLLBACK TO SAVEPOINT c2; END IF;
    SAVEPOINT c3;
    INSERT INTO Cars VALUES(4,'d', 1);      --Insert car 4 to Person 1 -> Not Allowed Rollback
    SELECT count(*) INTO countcar FROM Cars WHERE PersonID = 1 GROUP BY PersonID;
    IF(countcar > 3) THEN ROLLBACK TO SAVEPOINT c3; END IF;
    SAVEPOINT c4;
    INSERT INTO Cars VALUES(5,'e', 2);      --Insert car 5 to Person 2 -> Allowed
    SELECT count(*) INTO countcar FROM Cars WHERE PersonID = 2 GROUP BY PersonID;
    IF(countcar > 3) THEN ROLLBACK TO SAVEPOINT c4; END IF;
    SAVEPOINT c5;
    COMMIT;
END;


