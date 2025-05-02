set serveroutput on

--Q1
DECLARE
empid EMPLOYEES.EMPLOYEE_ID%type;
empsal employees.SALARY%type;
BEGIN
    empid:=&empid;
    
    SELECT HR.Employees.Salary 
    INTO empsal
    FROM HR.EMPLOYEES
    WHERE EMPLOYEE_ID = empid;
    
    dbms_output.put_line('Original Salary: ' || empsal);
    
    IF (empsal < 1000) THEN
        dbms_output.put_line('New Salary: ' || empsal * 1.1);
    ELSIF (empsal >= 1000 AND empsal < 1500) THEN
        dbms_output.put_line('New Salary: ' || empsal * 1.15);
    ELSIF (empsal >= 1500) THEN
        dbms_output.put_line('New Salary: ' || empsal * 1.2);
    ELSE 
        dbms_output.put_line('New Salary: ' || empsal);
    END IF;
END;
/

--Q2
DECLARE
    empid EMPLOYEES.EMPLOYEE_ID%type;
    empsal employees.SALARY%type;
    empcom EMPLOYEES.COMMISSION_PCT%type;
    newemp Number(2,2);
BEGIN
    empid := &empid;
    
    SELECT SALARY, COMMISSION_PCT
    INTO empsal, empcom
    FROM EMPLOYEES
    WHERE EMPLOYEE_ID = empid;
    
    newemp:=2.1;
    dbms_output.put_line('Original Salary: ' || empsal || empcom);
    IF (empcom > 0) THEN
        dbms_output.put_line('New Salary2: ' || empcom + newemp);
    ELSE
        dbms_output.put_line('New Salary1: ' || empsal);
    END IF;
END;
/

--Q3
DEClARE
    deptname DEPARTMENTS.DEPARTMENT_NAME%type;
BEGIN
    SELECT DEPARTMENTS.DEPARTMENT_NAME
    INTO deptname
    FROM DEPARTMENTS
    WHERE DEPARTMENT_ID = 30;
    
    dbms_output.put_line('Department Name: ' || deptname);
END;
/

--Q4
CREATE or replace FUNCTION FindNature(EMP_ID in Number)
RETURN JOBS.JOB_TITLE%type
IS
    Nature JOBS.JOB_TITLE%type;
BEGIN
    SELECT JOB_TITLE 
    INTO Nature 
    FROM Jobs 
    INNER JOIN EMPLOYEES ON EMPLOYEES.JOB_ID = Jobs.JOB_ID
    WHERE EMPLOYEES.EMPLOYEE_ID = EMP_ID;
    RETURN(Nature);
END;
/

DECLARE
    x number;
BEGIN
    dbms_output.put_line('New Salary2: ' || FindNature(120));
END;