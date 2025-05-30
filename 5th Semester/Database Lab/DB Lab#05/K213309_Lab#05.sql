--K213309 DB Lab05

--Task 1 ~ Write a query to list the name, job name, department name, salary of the employees according to the department in ascending order.
SELECT First_Name, Job_ID, Department_Name, Salary 
FROM Employees 
INNER JOIN Departments ON Employees.Department_ID = Departments.Department_ID 
ORDER BY (Department_Name) ASC;

--Task 2 ~ Write a query to list the department where at least two employees are working.
SELECT COUNT(*) as "NUMBER_OF_EMPLOYEES", Department_Name 
FROM Departments 
INNER JOIN Employees ON Employees.Department_ID = Departments.Department_ID 
GROUP BY (Departments.Department_Name) 
HAVING (COUNT(Department_Name)) >= 2;

--Task 3 ~ Fetch first_name, last_name, department_id, min_salary, max_salary of each employee;
SELECT First_name, Last_name, Department_id, min_salary, max_salary 
FROM Employees 
INNER JOIN Jobs ON Employees.Job_ID = Jobs.Job_ID;

--Task 4 ~ Write a query to list the name, job name, annual salary, department id,
--department name and city who earn 60000 in a year or not working as an ANALYST.
SELECT First_Name, Job_Title, Salary * 12 AS "ANNUAL_SALARY", Departments.Department_ID, Departments.Department_Name, City 
FROM Employees 
INNER JOIN JOBS ON Jobs.Job_ID = Employees.Job_ID
INNER JOIN Departments ON Employees.Department_ID = Departments.Department_ID
INNER JOIN Locations ON Departments.Location_ID = Locations.Location_ID
WHERE SALARY*12 = 60000 OR Jobs.Job_ID != 'ANALYST';

--Task 5 ~ Write a query to print details of the employees who are also Managers.
SELECT DISTINCT E1.* 
FROM Employees E1 
INNER JOIN Employees E2 ON E1.Employee_ID = E2.Manager_ID 
ORDER BY E1.EMPLOYEE_ID ASC;

--Task 6 ~ List department number, Department name for all the departments in which there are no employees in the department.
SELECT Departments.Department_ID, Department_Name 
FROM DEPARTMENTS 
LEFT OUTER JOIN EMPLOYEES ON Employees.Department_ID = Departments.Department_ID 
GROUP BY Departments.Department_ID,Department_Name 
HAVING COUNT(Employees.Department_ID) = 0;

--Task 7 ~ Display employee name, salary, department name where all employees has matching department as well as employee does not have any departments.
--Task 7 ~ Display employee name, salary, department name where all employees(unique) have matching departments.
SELECT DISTINCT E1.First_Name, E2.First_Name, E1.Salary, E2.Salary, E1.Department_ID, E2.Department_ID
FROM Employees E1 
INNER JOIN Employees E2
ON (E1.Employee_ID != E2.Employee_ID AND E1.Department_ID = E2.Department_ID);

--Task 8 ~ Display name, job ID, department name, street address and city of the employee in which there is no state province.
SELECT First_Name, Job_ID, Department_Name, Street_Address, City
FROM Employees 
INNER JOIN Departments ON Employees.DEPARTMENT_ID = Departments.DEPARTMENT_ID
INNER JOIN Locations ON Departments.LOCATION_ID = Locations.LOCATION_ID
WHERE State_Province IS NULL;

--Task 9 ~ Write an SQL query to show records from one table that another table does not have.
SELECT Employee_ID, Job_Id FROM Employees MINUS
SELECT Employee_ID, Job_Id FROM Job_History;

--Task 10 ~ Display all employees who belong to the country �US� but not belongs to state province Washington.
SELECT Employees.*
FROM Employees
INNER JOIN Departments ON Employees.Department_ID = Departments.Department_ID
INNER JOIN Locations ON Departments.Location_ID = Locations.Location_ID
INNER JOIN Countries ON Locations.Country_ID = Countries.Country_ID
WHERE Countries.Country_ID = 'US' AND Locations.State_Province != 'Washington';
