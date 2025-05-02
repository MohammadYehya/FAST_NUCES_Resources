set serveroutput on

--Q1
DECLARE
    num1 number;
    num2 number;
    MOD_ERROR EXCEPTION;
    DIV_ZERO EXCEPTION;
BEGIN
    num1 := &num1;
    num2 := &num2;
    
    IF (num2 = 0) THEN
        RAISE DIV_ZERO;
    ELSIF (MOD(num1 + num2, 2) = 0) THEN
        RAISE MOD_ERROR;
    END IF;
    dbms_output.put_line('SUM: ' || (num1 + num2));
EXCEPTION
    WHEN DIV_ZERO THEN  
         dbms_output.put_line('DIVIDE BY ZERO!');
    WHEN MOD_ERROR THEN
        dbms_output.put_line('EVEN SUM!');
END;
/
--Q2
CREATE OR REPLACE TYPE emp_data as OBJECT
(
    emp_id integer,
    first_name varchar(255),
    last_name varchar(255),
    department_name varchar(255),
    salary integer,
    job_title varchar(255)
);
/
DECLARE
    emp_det emp_data;
BEGIN
    SELECT emp_data(employee_id, first_name, last_name, departments.department_name, salary, jobs.job_title)    
    INTO emp_det
    FROM Employees INNER JOIN Departments ON Employees.Department_ID = Departments.Department_ID
    INNER JOIN JOBS ON Employees.Job_ID = Jobs.Job_id
    WHERE Employee_id = 140;
    
    dbms_output.put_line('Data: ' || (emp_det.emp_id) || ', ' || emp_det.first_name || ' ' || emp_det.last_name || ', ' || emp_det.department_name || ', ' || (emp_det.salary*1.05) || ', ' || emp_det.job_title);
END;
/
--Q3
DECLARE
    type emp_details is table of emp_data;
    emp_det emp_details;
BEGIN
    SELECT emp_data(employee_id, first_name, last_name, departments.department_name, salary, jobs.job_title)
    BULK COLLECT
    INTO emp_det
    FROM Employees
    INNER JOIN Departments ON Employees.Department_ID = Departments.Department_ID
    INNER JOIN JOBS ON Employees.Job_ID = Jobs.Job_id
    WHERE Employees.Department_ID = 90;
    
    FOR i IN 1..emp_det.COUNT LOOP
        dbms_output.put_line('Data: ' || (emp_det(i).emp_id) || ', ' || emp_det(i).first_name || ' ' || emp_det(i).last_name || ', ' || emp_det(i).department_name || ', ' || (emp_det(i).salary*1.05) || ', ' || emp_det(i).job_title);
    END LOOP;
END;
/

--Q4
DECLARE
    CURSOR Cursor_EMP IS
        SELECT * 
        FROM employees
        WHERE Employee_ID = 120;
    row_emp Cursor_EMP%ROWTYPE;
BEGIN
    OPEN Cursor_EMP;
    LOOP
        FETCH Cursor_EMP INTO row_emp;
        EXIT WHEN Cursor_EMP%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE( 'EMPLOYEE id: ' || row_emp.EMPLOYEE_ID || ' EMPLOYEE NAME: ' || row_emp.FIRST_NAME || ' EMPLOYEE DEPARTMENT_ID: ' || row_emp.DEPARTMENT_ID || 'EMPLOYEE JOB_ID: ' || row_emp.Job_ID || '.');
    END LOOP;
    CLOSE Cursor_EMP;
END;
/

--Q5
DECLARE
    CURSOR Cursor_EMP IS
        SELECT * 
        FROM employees
        WHERE Employee_ID >= 101 AND Employee_ID <= 145;
    row_emp Cursor_EMP%ROWTYPE;
BEGIN
    OPEN Cursor_EMP;
    LOOP
        FETCH Cursor_EMP INTO row_emp;
        EXIT WHEN Cursor_EMP%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE( 'EMPLOYEE id: ' || row_emp.EMPLOYEE_ID || ' EMPLOYEE NAME: ' || row_emp.FIRST_NAME || ' EMPLOYEE DEPARTMENT_ID: ' || row_emp.DEPARTMENT_ID || 'EMPLOYEE JOB_ID: ' || row_emp.Job_ID || '.');
    END LOOP;
    CLOSE Cursor_EMP;
END;
/

--Q6
CREATE TABLE Sellers
(
    SellerID NUMBER PRIMARY KEY
);
CREATE TABLE Buyer
(
    BuyerID NUMBER PRIMARY KEY
);

--Q7
CREATE TABLE Statements
(
    StatementID NUMBER PRIMARY KEY
);
CREATE TABLE Queries
(
    QueryID NUMBER PRIMARY KEY
);

--Q8
CREATE TABLE Transcations
(
    TranscationID NUMBER PRIMARY KEY
);

--Q9
CREATE OR REPLACE TRIGGER Tstatement
BEFORE INSERT OR UPDATE OR DELETE 
ON Statement
FOR EACH ROW
BEGIN
    --
END;
