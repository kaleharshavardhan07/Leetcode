# Write your MySQL query statement below
select employee_id , department_id   from Employee
where primary_flag='Y'
union
SELECT employee_id, department_id
FROM Employee
WHERE employee_id NOT IN (
    SELECT employee_id
    FROM Employee
    WHERE primary_flag = 'Y'
) AND (
    SELECT COUNT(*)
    FROM Employee AS e2
    WHERE e2.employee_id = Employee.employee_id
) = 1;