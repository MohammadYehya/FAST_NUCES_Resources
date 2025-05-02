--DB LAB 2 HOME TASKS
--K213309

--Task 1 ~ Fetch the bottom 10 values from the employees table w.r.t to employee ID.
SELECT EMPLOYEE_ID FROM EMPLOYEES WHERE ROWNUM <= 10 ORDER BY EMPLOYEE_ID DESC;

--Task 2 ~ List the departments with the most employees from top to bottom (department ID can’t be NULL).
SELECT DEPARTMENT_ID, COUNT(DEPARTMENT_ID) FROM EMPLOYEES WHERE DEPARTMENT_ID IS NOT NULL GROUP BY DEPARTMENT_ID ORDER BY COUNT(DEPARTMENT_ID) DESC;

--Task 3 ~ Display the employee number, name, salary of employee before and after 15% increment.
--Name the calculated new salary as 'Incremented Salary' and calculate the difference between two salaries.
--Name the increased amount to be 'Incremented Amount'.
SELECT FIRST_NAME || ' ' || LAST_NAME AS "Full Name", EMPLOYEE_ID, SALARY, SALARY * 1.15 AS "Incremented Salary", SALARY * 0.15 AS "Incremented Amount" FROM employees;

--Task 4 ~ Display the department and manager id wise avg commission for all employees.
--Round the commission up to 2 decimals, filter any null values.
SELECT ROUND(AVG(COMMISSION_PCT),2), MANAGER_ID, DEPARTMENT_ID FROM EMPLOYEES WHERE COMMISSION_PCT IS NOT NULL AND DEPARTMENT_ID IS NOT NULL GROUP BY MANAGER_ID, DEPARTMENT_ID;