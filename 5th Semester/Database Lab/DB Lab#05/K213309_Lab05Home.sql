--K213309 Lab05 Home Tasks

--TASK 1 ~ Create a table named Students having attributes (Student_id, FullName, Age, Gender, EnrollmentDate, and CGPA). Student_id being primary key.  
CREATE TABLE Students
(Student_ID NUMBER PRIMARY KEY, 
FullName VARCHAR(255), 
AGE NUMBER, 
Gender VARCHAR(255), 
EnrollentDate VARCHAR(255), 
CGPA NUMBER);

--TASK 2 ~ Create another table named Courses having attributes (Course_id, course_title, Credits, and OfferedinSemester). Course_id being primary.
CREATE TABLE Courses
(Course_ID VARCHAR(255) PRIMARY KEY,
Course_Title VARCHAR(255),
Credits NUMBER,
OfferedSemester NUMBER);

--TASK 3 ~ Make another table Transcript having attributes (student_id, course_id, GPA and Grade). 
CREATE TABLE Transcript
(Student_ID NUMBER,
Course_ID VARCHAR(255),
GPA NUMBER,
Grade VARCHAR(255),
FOREIGN KEY (Student_ID) REFERENCES Students(Student_ID) ON DELETE CASCADE,
FOREIGN KEY (Course_ID) REFERENCES Courses(Course_ID) ON DELETE CASCADE);

--TASK 4 ~ Grade ranges from 'A' to 'F' such that if GPA is:
--a. Less than 2 -> grade F.
--b. 2 -> grade E.
--c. 2.5 -> grade D.
--d. 3 -> grade C.
--e. 3.5 -> grade B.
--f. 4 -> grade A.
ALTER TABLE Transcript
ADD CHECK(((GPA < 2 AND Grade = 'F') 
            OR (GPA >= 2 AND GPA < 2.5 AND Grade = 'E') 
            OR (GPA >= 2.5 AND GPA < 3 AND Grade = 'D') 
            OR (GPA >= 3 AND GPA < 3.5 AND Grade = 'C') 
            OR (GPA >= 3.5 AND GPA < 4 AND Grade = 'B') 
            OR (GPA = 4 AND Grade = 'A'))
            AND (GPA >= 1 AND GPA <= 4));
            
--TASK 5 ~ Create a relationship between Courses -> Transcript, Courses being the parent table. 
--Create another relationship between Students -> Transcript, Students being the parent table.
DONE ABOVE BY CREATING FOREIGN KEYS

--TASK 6 ~ Filled the students table with 6 rows of data, the first containing your own data, and the remaining 5 containing random data (excluding your classmates).
INSERT INTO Students VALUES(3309, 'Mohammad Yehya', 20, 'Male', '14-Aug-2021', 3.99);
INSERT INTO Students VALUES(1234, 'XYZ', 19, 'Female', '', 3.75);
INSERT INTO Students VALUES(5678, 'ABC', 21, 'Male', '', 3.12);
INSERT INTO Students VALUES(9012, 'DEF', 20, 'Female', '', 2.86);
INSERT INTO Students VALUES(3456, 'GHI', 22, 'Male', '', 2.95);
INSERT INTO Students VALUES(7890, 'JKL', 20, 'Female', '', 2.05);
INSERT INTO Students VALUES(9632, 'MNO', 22, 'Female', '', 2.22);

--TASK 7 ~ Fill the Courses table with data from your curriculum.
INSERT INTO Courses VALUES('CS3006', 'Parallel And Distributed Computing', 3, 5);
INSERT INTO Courses VALUES('CS2009', 'Design And Analysis of Algorithms', 3, 5);
INSERT INTO Courses VALUES('MT3001', 'Graph Theory', 3, 5);
INSERT INTO Courses VALUES('CS2005', 'Database Systems', 4, 5);
INSERT INTO Courses VALUES('CS3004', 'Software Design And Analysis', 3, 5);
INSERT INTO Courses VALUES('CS1002', 'Programming Fundamentals', 3, 1);

--TASK 8 ~ Fill in the transcript table in such a way that each student must be enrolled in at least 3 courses. 
INSERT INTO Transcript VALUES(3309, 'CS3006', 4, 'A');
INSERT INTO Transcript VALUES(3309, 'CS2009', 4, 'A');
INSERT INTO Transcript VALUES(3309, 'MT3001', 4, 'A');

INSERT INTO Transcript VALUES(1234, 'CS2005', 3.33, 'C');
INSERT INTO Transcript VALUES(1234, 'CS3004', 3.67, 'B');
INSERT INTO Transcript VALUES(1234, 'CS3006', 4, 'A');

INSERT INTO Transcript VALUES(5678, 'CS2009', 3, 'C');
INSERT INTO Transcript VALUES(5678, 'MT3001', 2.67, 'D');
INSERT INTO Transcript VALUES(5678, 'CS2005', 2.33, 'E');

INSERT INTO Transcript VALUES(9012, 'CS3004', 2, 'E');
INSERT INTO Transcript VALUES(9012, 'CS3006', 1.67, 'F');
INSERT INTO Transcript VALUES(9012, 'CS2009', 2.33, 'E');

INSERT INTO Transcript VALUES(3456, 'MT3001', 2.67, 'D');
INSERT INTO Transcript VALUES(3456, 'CS2005', 2.33, 'E');
INSERT INTO Transcript VALUES(3456, 'CS3004', 3, 'C');

INSERT INTO Transcript VALUES(7890, 'CS3006', 3.33, 'C');
INSERT INTO Transcript VALUES(7890, 'CS2009', 3.67, 'B');
INSERT INTO Transcript VALUES(7890, 'MT3001', 2.33, 'E');

--TASK 9 ~ Make sure that the GPA in Transcript is never less than 1 or greater than 4. 
--Also, make sure that the Grade lies within the range specified above in task#4.
DONE ABOVE

--TASK 10 ~ The CGPA in the student table should be the average GPA of all courses the student is enrolled in.
DONE ABOVE

--TASK 11 ~ Display details of each student along with the details of courses they are enrolled in, their GPA, CGPA, GRADE etc. 
--In short, display all details in the 3 tables.
SELECT *
FROM Students S
INNER JOIN Transcript T
ON S.Student_ID = T.Student_ID
INNER JOIN Courses C
ON T.Course_ID = C.Course_ID;

--TASK 12 ~ Display the number of courses each student is enrolled in, along with their CGPA, Name and Student_id in ascending order.
SELECT COUNT(T.Course_ID), S.CGPA, S.FullName, S.Student_ID 
FROM Students S 
INNER JOIN Transcript T 
ON S.Student_ID = T.Student_ID
GROUP BY S.Student_ID, S.CGPA, S.FullName
ORDER BY S.Student_ID ASC;

--TASK 13 ~ Delete the details of students with less than 2 CGPA and either nullify the values in referencing table OR delete the records completely.
DELETE FROM Students WHERE CGPA < 2;

--TASK 14 ~ Display the number of students enrolled in each Course, along with the Course_title and Course_id in ascending order. 
SELECT COUNT(*), T.Course_ID, C.Course_Title
FROM Transcript T
INNER JOIN Courses C
ON T.Course_ID = C.Course_ID
GROUP BY T.Course_ID, C.Course_Title;

--TASK 15 ~ Count the number of students having the same Grade.
SELECt Grade, COUNT(DISTINCT Student_ID)
FROM Transcript
GROUP BY Grade
ORDER BY Grade;

--TASK 16 ~ List courses which don’t have any students enrolled in them. Similarly, list students which aren’t enrolled in any courses.
SELECT C.Course_Title
FROM Courses C
WHERE C.Course_ID != ALL(SELECT T.Course_ID 
                        FROM Transcript T);

SELECT S.FullName
FROM Students S
WHERE S.Student_ID != ALL(SELECT T.Student_ID
                        FROM Transcript T);