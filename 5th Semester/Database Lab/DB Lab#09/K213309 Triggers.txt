--Trigger Questions
set serveroutput on
--Q6
CREATE TABLE Sellers
(
    SellerID NUMBER PRIMARY KEY,
    Value NUMBER
);
CREATE TABLE Buyer
(
    BuyerID NUMBER PRIMARY KEY,
    Value NUMBER
);

--Q7
CREATE TABLE Statements
(
    StatementID NUMBER PRIMARY KEY
);
CREATE TABLE Queries
(
--    QueryID NUMBER PRIMARY KEY,
    Value1 NUMBER,
    Value2 NUMBER
);
--Q8
CREATE TABLE Transactions
(
    buyer_ID NUMBER,
    seller_ID NUMBER,
    price NUMBER
);

--Q9
CREATE OR REPLACE TRIGGER Tstatement
BEFORE INSERT OR UPDATE OR DELETE
ON Statements
BEGIN
    dbms_output.put_line('Insert/Update/Delete statement executed');
END;
/
INSERT INTO Statements VALUES(1);
UPDATE Statements SET StatementID = 2 WHERE StatementID != 2;
DELETE Statements WHERE StatementID = 2;
SELECT * FROM STATEMENTS;

--Q10
CREATE OR REPLACE TRIGGER BuyerDel
BEFORE DELETE
ON Buyer
FOR EACH ROW
BEGIN
    INSERT INTO QUERIES VALUES(:OLD.Value, 0);
END;
/
CREATE OR REPLACE TRIGGER SellerDel
BEFORE DELETE
ON Sellers
FOR EACH ROW
BEGIN
    INSERT INTO QUERIES VALUES(:OLD.Value, 0);
END;
/
CREATE OR REPLACE TRIGGER BuyerIns
BEFORE INSERT
ON Buyer
FOR EACH ROW
BEGIN
    INSERT INTO QUERIES VALUES(0, :New.Value);   
END;
/
CREATE OR REPLACE TRIGGER SellerIns
BEFORE INSERT
ON Sellers
FOR EACH ROW
BEGIN
    INSERT INTO QUERIES VALUES(0, :New.Value);   
END;
/
CREATE OR REPLACE TRIGGER BuyerUpd
BEFORE UPDATE
ON Buyer
FOR EACH ROW
BEGIN
    INSERT INTO QUERIES VALUES(:OLD.Value, :New.Value);
END;
/
CREATE OR REPLACE TRIGGER SellerUpd
BEFORE UPDATE
ON Sellers
FOR EACH ROW
BEGIN
    INSERT INTO QUERIES VALUES(:OLD.Value, :New.Value);
END;
/

SELECT * FROM Buyer;
SELECT * FROM Sellers;
SELECT * FROM Queries;

INSERT INTO Sellers VALUES(1, 2500);
UPDATE Sellers SET Value = 3000 WHERE value = 2500;
DELETE Sellers WHERE Value = 3000;
TRUNCATE TABLE Queries;

--Q11
DECLARE
    sell_id NUMBER;
    buy_id NUMBER;
    price number;
BEGIN
    sell_id := &sell_id;
    buy_id := &buy_id;
    price := &price;
    INSERT INTO Sellers VALUES(sell_id, price);
    INSERT INTO Buyer VALUES(buy_id, price);
    INSERT INTO Transactions VALUES(buy_id, sell_id, price);
END;
/
SELECT * FROM Buyer;
SELECT * FROM Sellers;
SELECT * FROM Transactions;

--Q12
CREATE OR REPLACE FUNCTION getDetails(e_id Employees.Employee_ID%type)
RETURN VARCHAR
AS
    fullName VARCHAR(255);
BEGIN
    SELECT FIRST_NAME || ' ' || LAST_NAME INTO fullName FROM Employees WHERE Employee_ID = e_id AND e_id >= 110;
    RETURN fullName;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        SELECT FIRST_NAME || ' ' || LAST_NAME INTO fullName FROM Employees WHERE Employee_ID = 110;
        RETURN fullName;
END;
/
CREATE OR REPLACE PROCEDURE getID
AS
    e_id Employees.Employee_ID%type;
    fullName VARCHAR(255);
BEGIN
    e_id := &e_id;
    dbms_output.put_line(getDetails(e_id));
END;
/
DECLARE
BEGIN
    getID();
END;
/