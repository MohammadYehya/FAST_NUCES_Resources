set serveroutput on;

create or replace type emp_data as OBJECT (
    emp_id integer,
    first_name varchar(30),
    last_name varchar(30),
    department_id integer
);
/

declare
emp_det emp_data;

--type emp_details is table of emp_data;
--emp_det emp_details;
begin
select emp_data(employee_id, first_name, last_name, department_id)
--bulk collect 
into emp_det
from employees
where employee_id = 120;

--FOR i IN 1..emp_det.COUNT LOOP
    DBMS_OUTPUT.PUT_LINE('Data: ' || emp_det.first_name);
--END LOOP;
end;
/

