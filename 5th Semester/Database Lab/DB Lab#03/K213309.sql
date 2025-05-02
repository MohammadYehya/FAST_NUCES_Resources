--Task 1 ~ Using wildcards, perform the following tasks:
--Get all Employees having 'A' anywhere in their names.
SELECT * FROM HR.EMPLOYEES WHERE FIRST_NAME LIKE '%A%';
--Get all Employees having 'e' as 2 nd last character.
SELECT * FROM HR.EMPLOYEES WHERE FIRST_NAME LIKE '%e_';
--Get all Employees having 'l' (small L, not i) as 2nd character.
SELECT * FROM HR.EMPLOYEES WHERE FIRST_NAME LIKE '_l%';
--Get all Employees having 'l' as 2nd character and 'n' as 4th character.
SELECT * FROM HR.EMPLOYEES WHERE FIRST_NAME LIKE '_l_n%';

--Task 2 ~ Create a new user using SQL command Line and grant privileges. The user should be named after your roll number with lab03 as prefix.
--Done

--Task 3 ~ Create a table Employees with attributes(columns) named Employee_id, Full_Name, Salary, Department_id, Start_Date, End_Date, Married, Phone_No.
CREATE TABLE Employees (Employee_id INT, Full_Name VARCHAR(255) NOT NULL, 
                        Salary INT NOT NULL, Department_id INT, Start_Date INT NOT NULL,
                        End_Date INT NOT NULL, Married VARCHAR(255), Phone_No VARCHAR(255));
                        
--Task 4 ~ Create another table Departments with attributes(columns) named Department_id, Department_name, Department_code, Date_Founded.
CREATE TABLE Departments (Department_id INT, Department_name VARCHAR(255), Department_code VARCHAR(255), Date_Founded INT);

--Task 5 ~ Make sure the department names are unique and check if the date_founded is greater than 2000.
ALTER TABLE Departments MODIFY Department_name VARCHAR(255) UNIQUE;
ALTER TABLE Departments ADD CHECK(Date_Founded > 2000);

--Task 6 ~ Make sure that you set the IDs in each table to primary keys.
ALTER TABLE Employees MODIFY Employee_id INT PRIMARY KEY;
ALTER TABLE Departments MODIFY Department_id INT PRIMARY KEY;

--Task 7 ~ Make use of alter command to add foreign key constraint and pass reference of departments to the employees table using has-belongs to concept.
ALTER TABLE Employees ADD FOREIGN KEY (Department_id) REFERENCES Departments (Department_id);

--Task 8 ~ Insert 5 rows of data into both tables.
INSERT INTO Departments VALUES(1,'DEP_A', 'ACS', 2001);
INSERT INTO Departments VALUES(2,'DEP_B', 'BCS', 2011);
INSERT INTO Departments VALUES(3,'DEP_C', 'CCS', 2020);
INSERT INTO Departments VALUES(4,'DEP_D', 'DCS', 2021);
INSERT INTO Departments VALUES(5,'DEP_E', 'ECS', 2019);

INSERT INTO Employees VALUES(1,'ABC', 500, 5, 1984, 2011, 'Y', '123');
INSERT INTO Employees VALUES(2,'DEF', 200, 3, 2011, 2021, 'Y', '456');
INSERT INTO Employees VALUES(3,'GHI', 50000, 4, 1, 2022, 'N', '789');
INSERT INTO Employees VALUES(4,'JKL', 1000, 1, 2019, 2021, 'Y', '101112');
INSERT INTO Employees VALUES(5,'MNO', 2000, 2, 2016, 2020, 'N', '131415');

--Task 9 ~ Add Column Speciality in Departments table and set its default value to None.
ALTER TABLE Departments ADD Speciality VARCHAR(255) DEFAULT NULL;

--Task 10 ~ Create a table named Jobs with attributes being the same as the table from HR.
CREATE TABLE Jobs (Job_id VARCHAR(255), Job_title VARCHAR(255), MIN_SALARY INT, MAX_SALARY INT);

--Task 11 ~ Modify the Job_id to be of Integer Type and make it the primary key.
ALTER TABLE Jobs MODIFY Job_id INT PRIMARY KEY;

--Task 12 ~ Write a SQL statement to add Employee_id column in jobs table as foreign key referencing to the primary key Employee_id of Employees table.
ALTER TABLE Jobs ADD Employee_id INT;
ALTER TABLE Jobs ADD FOREIGN KEY (Employee_id) REFERENCES Employees (Employee_id);

--Task 13 ~ Insert 3 rows of data into jobs table.
INSERT INTO Jobs VALUES(101, 'President', 20080, 40000, 1);
INSERT INTO Jobs VALUES(121, 'Administration Vice President', 15000, 30000, 2);
INSERT INTO Jobs VALUES(150, 'Administration Assistant', 3000, 6000, 3);

--Task 14 ~ Drop column speciality from Departments.
ALTER TABLE Departments DROP COLUMN Speciality;

--Task 15 ~ Truncate the jobs table.
TRUNCATE TABLE Jobs;

--Task 16 ~ Insert 4 new rows into jobs table.
INSERT INTO Jobs VALUES(196, 'Finance Manager', 8200, 16000, 1);
INSERT INTO Jobs VALUES(143, 'Accountant', 4200, 9000, 2);
INSERT INTO Jobs VALUES(178, 'Accounting Manager', 8200, 16000, 3);
INSERT INTO Jobs VALUES(199, 'Public Accountant', 4200, 9000, 4);

--Task 17 ~ ALTER table EMPLOYEE and apply the constraint CHECK on Full_Name attribute such that it should always be capitalized.
ALTER TABLE Employees ADD CHECK(UPPER(FULL_NAME) = FULL_NAME);

--Task 18 ~ Change table Employee and make sure that Phone_No should be unique, and never empty.
ALTER TABLE Employees MODIFY Phone_No NOT NULL UNIQUE;

--Task 19 ~ Write a SQL statement to insert one row into the table Employees.
INSERT INTO Employees VALUES(6,'PQR', 50000, 2, 2010, 2020, 'Y', '161718');

--Task 20 ~ Write a SQL statement to increase the salary of an employee by 200% if the existing salary is less than 1000.
UPDATE Employees SET Salary = Salary * 3 WHERE SALARY < 1000;

--Task 21 ~ Change column name Phone_No to Phone_Number, and change jobs table to be job_details, make sure to change foreign keys where referenced.
ALTER TABLE Employees RENAME COLUMN Phone_no TO Phone_Number;
ALTER TABLE Jobs RENAME TO Job_Details;

--Task 22 ~ Write a SQL statement to add a primary key for a combination of columns employee_id and job_id in employees table, give the reason why this command is showing error.
ALTER TABLE Employees ADD PRIMARY KEY(employee_id, job_id);
        --This is giving an error because first of all there is no column named job_id in employees table
        --Secondly you can not have 2 primary keys in one table

--Task 23 ~ Delete a row from jobs_details table where starting year is below 1990(add a record first if not existent).
DELETE FROM Job_Details WHERE employee_id IN (SELECT employee_id FROM Employees WHERE start_date < 1990);

--Task 24 ~ Drop the job_details table.
DROP TABLE Job_Details;
--Task 25 ~ Write a SQL statement to add an index named indx_employee_id on employee_id column in the table employees,
--indx_department_id on department_id column in the table departments.
CREATE UNIQUE INDEX indx_employee_id ON Employees (employee_id);
CREATE UNIQUE INDEX indx_department_id ON Departments (Department_id);