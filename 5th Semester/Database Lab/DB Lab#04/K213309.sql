--K213309 Home Tasks

DROP TABLE Student;
DROP TABLE Course;

--Task 1 ~ Create a table named Student having attributes name, age, gender, roll_number, semester, warning, CGPA, and Department (at least 3).
CREATE TABLE Student (Name VARCHAR(255), Age INT, Gender VARCHAR(255), Roll_Number INT, Semester INT, Warning INT NOT NULL, CGPA FLOAT, Department VARCHAR(255));

--Task 2 ~ Create another table named Course having attributes course_code, course_name, and credit_hours.
CREATE TABLE Course (Course_Code VARCHAR(255), Course_Name VARCHAR(255), Credit_Hours INT);

--Task 3 ~ Make course_code primary key for Course table and roll_number for Student.
ALTER TABLE Course ADD PRIMARY KEY (Course_Code);
ALTER TABLE Student ADD PRIMARY KEY (Roll_Number);

--Task 4 ~ Add a check on gender to make sure that it’s either Male or Female.
ALTER TABLE Student ADD CHECK(Gender = 'Male' OR Gender = 'Female');

--Task 5 ~ Make sure that the course_name is never repeated.
ALTER TABLE Course MODIFY Course_Name VARCHAR(255) UNIQUE;

--Task 6 ~ Change column name course_name to course_title.
ALTER TABLE Course RENAME COLUMN Course_Name TO Course_Title;

--Task 7 ~ Make sure that if no value is assigned to warning column, it should be 0.
ALTER TABLE Student MODIFY Warning DEFAULT 0;

--Task 8 ~ Fill the above table with your own data as the first-row entry. The remaining entries should be random and not include your classmates/friends.
INSERT INTO Student VALUES('Mohammad Yehya',    20, 'Male',     3309,   5, 0,   3.99,   'CS');
INSERT INTO Student VALUES('ABC XYZ',           22, 'Male',     1234,   7, 1,   2.22,   'CYS');
INSERT INTO Student VALUES('PQR STU',           21, 'Female',   2454,   5, 0,   3.32,   'SE');
INSERT INTO Student VALUES('EFG HIJ',           19, 'Female',   4648,   3, 1,   3.0,    'AI');
INSERT INTO Student VALUES('KLM NOP',           25, 'Male',     3424,   7, 0,   2.4,    'EE');
INSERT INTO Student VALUES('AXZ BPR',           19, 'Female',   3222,   2, 0,   3.6,    'CS');
INSERT INTO Student VALUES('ZYX CBA',           21, 'Male',     1142,   3, 0,   3.6,    'AI');

--Task 9 ~ Fill the above table with 7-9 Core courses from your CS program and add 3-4 random electives as well (at least 10 rows of data in total).
INSERT INTO Course VALUES('EE117', 'Applied Physics', 3);
INSERT INTO Course VALUES('MT1003', 'Calculas and Analytical Geometry', 3);
INSERT INTO Course VALUES('CS217', 'Objectg Oriented Programming', 4);
INSERT INTO Course VALUES('MT224', 'Differential Equations', 3);
INSERT INTO Course VALUES('CS2001', 'Data Structures', 4);
INSERT INTO Course VALUES('EE2003', 'Computer Organization and Assembly Language', 4);
INSERT INTO Course VALUES('CS2006', 'Operating Systems', 4);
INSERT INTO Course VALUES('CS2008', 'Numerical Computing', 3);
INSERT INTO Course VALUES('MG1001', 'Fundamentals of Management', 3);
INSERT INTO Course VALUES('AF1001', 'Fundamentals of Accouting', 3);
INSERT INTO Course VALUES('SS127', 'Sociology', 3);

--Task 10 ~ Write a query to retrieve the total number of Students in each department.
SELECT Department, COUNT(Department) as "NUMBER OF STUDENTS" FROM Student GROUP BY Department;

--Task 11 ~ Write a query to Filter the Students with CGPA of more than 2.5.
SELECT * FROM Student WHERE CGPA > 2.5;

--Task 12 ~ Write a query to retrieve the bottom 3 students.
SELECT * FROM (SELECT ROWNUM r, STUDENT.* FROM STUDENT) WHERE r > ((SELECT COUNT(Roll_Number) FROM STUDENT) - 3);

--Task 13 ~ Retrieve details of the student(s) with the best CGPA.
SELECT * FROM Student WHERE CGPA = ANY(SELECT MAX(CGPA) FROM STUDENT);

--Task 14 ~ Retrieve details of the student(s) with the worst CGPA.
SELECT * FROM Student WHERE CGPA = ANY(SELECT MIN(CGPA) FROM STUDENT);

--Task 15 ~ Retrieve details of student(s) that belong to either CS or EE department (you can’t use OR operator).
SELECT * FROM Student WHERE Department IN ('CS','EE');

--Task 16 ~ Retrieve details of student(s) that have the same number of warnings as any of students with the worst CGPA.
SELECT * FROM Student WHERE Warning = (SELECT Warning FROM Student WHERE CGPA = ANY(SELECT MIN(CGPA) FROM STUDENT));

--Task 17 ~ Retrieve details of student(s) that are in the same department as the student with CGPA 3.6. 
--If more than one department has students with 3.6 CGPA, it shouldn’t return anything.
SELECT * FROM Student WHERE Department = ALL(SELECT Department FROM Student WHERE CGPA = 3.6);

--Task 18 ~ Delete records of students whose warning count is less than the average warning count.
DELETE FROM Student WHERE Warning < (SELECT AVG(Warning) FROM Student);