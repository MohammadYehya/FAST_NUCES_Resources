--DB Assignment#1 K213309

--Q2
--Student(snum: integer, sname: string, major: string, level: string, age: integer)
CREATE TABLE Student (snum INT PRIMARY KEY, sname VARCHAR(255) NOT NULL, major VARCHAR(255), level_ VARCHAR(255), age INT);
DROP TABLE Student;

--Class( name: string, meets_at: time, room: string, fid: integer)
CREATE TABLE Class(cname VARCHAR(255), meets_at VARCHAR(255), room VARCHAR(255), fid INT);
DROP TABLE Class;

--Enrolled(snum: integer, cname: string)
CREATE TABLE Enrolled(snum INT, cname VARCHAR(255), FOREIGN KEY (snum) REFERENCES Student(snum));
DROP TABLE Enrolled;

--Faculty(fid: integer, fnarne: string, deptid: integer)
CREATE TABLE Faculty(fid INT PRIMARY KEY, fname VARCHAR(255), deptid INT);
ALTER TABLE Class ADD FOREIGN KEY (fid) REFERENCES Faculty(fid);
DROP TABLE Faculty;

--Inserting Values
INSERT INTO Faculty VALUES(101, 'I. Teach', 423);
INSERT INTO Class VALUES('Database', '2pm', 'R128', 101);
INSERT INTO Class VALUES('Data Structures', '1pm', 'R12', 101);
INSERT INTO Class VALUES('Computer Networks','11am', 'R11', 101);
INSERT INTO CLASS VALUES('Database','10am','R11', 101);
INSERT INTO CLASS VALUES('Numerical Computing', '8am', 'R12', 101);

INSERT INTO Faculty VALUES(123, 'XYZ', 679);
INSERT INTO Class VALUES('Programming Fundamentals', '2pm', 'R11', 123);

INSERT INTO Student VALUES(3309, 'Mohammad Yehya', 'CS', 'JR', 20);
INSERT INTO Enrolled VALUES(3309, 'Database');

INSERT INTO Student VALUES(1234, 'ABCDE', 'CS', 'FM', 19);
INSERT INTO Enrolled VALUES(1234, 'Data Structures');

INSERT INTO Student VALUES(5678, 'FGHI', 'AI', 'JR', 21);
INSERT INTO Enrolled VALUES(5678, 'Database');

INSERT INTO Student VALUES(9101, 'JKLM', 'SE', 'JR', 22);
INSERT INTO Enrolled VALUES(9101, 'Programming Fundamentals');

INSERT INTO Student VALUES(5237, 'NOP', 'SE', 'JR', 20);
INSERT INTO Enrolled VALUES(5237, 'Programming Fundamentals');

INSERT INTO Student VALUES(4861, 'QRS', 'CY', 'SP', 20);
INSERT INTO Enrolled VALUES(4861, 'Programming Fundamentals');

INSERT INTO Student VALUES(3432, 'TUV', 'CS', 'FM', 20);
INSERT INTO Enrolled VALUES(3432, 'Programming Fundamentals');
INSERT INTO Enrolled VALUES(3432, 'Database');

INSERT INTO Student VALUES(4555, 'WX', 'History', 'SP', 20);
INSERT INTO Enrolled VALUES(4555, 'Programming Fundamentals');

INSERT INTO Student VALUES(5555, 'YZ', 'CY', 'SO', 22);

INSERT INTO Student VALUES(2010, 'AA', 'AI', 'SP', 20);

INSERT INTO Student VALUES(6140, 'BB', 'CY', 'SO', 22);

--TASK 1 ~ Find the names of all Juniors (level = JR) who are enrolled in a class taught by I. Teach.
SELECT * 
FROM STUDENT 
WHERE level_ = 'JR' AND 
snum = ANY(
    SELECT snum 
    FROM Enrolled 
    WHERE cname = ANY(
        SELECT cname 
        FROM Class 
        WHERE fid = ANY(
            SELECT fid 
            FROM Faculty 
            WHERE fname = 'I. Teach')));

--TASK 2 ~ Find the age of the oldest student who is either a History major or enrolled in a course taught by I. Teach.
SELECT MAX(Age) 
FROM Student 
WHERE major = 'History' OR 
snum = ANY(
    SELECT snum 
    FROM Enrolled 
    WHERE cname = ANY(
        SELECT cname 
        FROM Class 
        WHERE fid = ANY(
            SELECT fid 
            FROM Faculty 
            WHERE fname = 'I. Teach'))); 

--TASK 3 ~ Find the names of all classes that either meet in room R128 or have five or more students enrolled.
SELECT * 
FROM Class 
WHERE room = 'R128' OR cname = ANY(
    SELECT cname 
    FROM Enrolled 
    GROUP BY cname 
    HAVING COUNT(*) >= 5);

--TASK 4 ~ Find the names of all students who are enrolled in two classes that meet at the same time.
SELECT * 
FROM Student 
WHERE snum = ANY(
    SELECT snum 
    FROM Enrolled 
    WHERE cname = ANY(
        SELECT cname 
        FROM CLASS 
        WHERE meets_at = ANY(
            SELECT meets_at 
            FROM CLASS)) 
        GROUP BY (snum) 
        HAVING COUNT(snum) >= 2);

--TASK 5 ~ Find the names of faculty members who teach in every room in which some class is taught.
SELECT *
FROM Faculty 
WHERE FID = ANY(
    SELECT FID 
    FROM CLASS 
    GROUP BY FID 
    HAVING COUNT(DISTINCT(room)) = ANY(
        SELECT COUNT(*) 
        FROM (
            SELECT DISTINCT ROOM 
            FROM CLASS)));

--TASK 6 ~ Find the names of faculty members for whom the combined enrollment of the courses that they teach is less than five.
SELECT * 
FROM Faculty 
WHERE FID = ANY(
    SELECT FID 
    FROM CLASS 
    WHERE cname = ANY(
        SELECT cname 
        FROM Enrolled 
        GROUP BY cname 
        HAVING COUNT(cname) < 5));

--TASK 7 ~ Print the level and the average age of students for that level, for each level.
SELECT level_, AVG(Age)
FROM Student
GROUP BY level_;

--TASK 8 ~ Print the level and the average age of students for that level, for all levels except JR.
SELECT level_, AVG(Age)
FROM Student
WHERE level_ != 'JR'
GROUP BY level_;

--TASK 9 ~ For each faculty member that has taught classes only in room R128, print the faculty member's name and the total number of classes she or he has taught.
--------------------------------------------------------------------------------------------------------------------------------------------------------------
SELECT *
FROM Faculty
WHERE fid = ANY(
    SELECT fid 
    FROM CLASS 
    WHERE ROOM = 'R128' 
    GROUP BY FID 
    HAVING COUNT(DISTINCT ROOM) = 1); 

--TASK 10 ~ Find the names of students enrolled in the maximum number of classes.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
SELECT *
FROM Student
WHERE snum = ANY(
    SELECT snum 
    FROM Enrolled 
    WHERE cname = ANY(
        SELECT cname 
        FROM ENROLLED 
        GROUP BY cname 
        HAVING count(cname) = ANY(
            SELECT MAX(mycount) 
            FROM (
                SELECT count(cname) mycount 
                FROM Enrolled 
                GROUP BY cname))));

--TASK 11 ~ Find the names of students not enrolled in any class.
SELECT *
FROM Student
WHERE snum != ALL(
    SELECT snum 
    FROM ENROLLED);

--TASK 12 ~ For each age value that appears in Students, find the level value that appears most often. 
--Forexample, if there are more FR level students aged 18 than SR, JR, or SO students aged 18, you should print the pair (18, FR).
SELECT Age, level_
FROM Student S
GROUP BY Age, level_
HAVING level_ = ANY(
    SELECT S1.level_ 
    FROM Student S1 
    WHERE S1.age = S.age 
    GROUP BY S1.level_, S1.age 
    HAVING COUNT(*) >= ALL(
        SELECT COUNT(*) 
        FROM Student S2 
        WHERE S1.age = S2.age 
        GROUP BY level_));