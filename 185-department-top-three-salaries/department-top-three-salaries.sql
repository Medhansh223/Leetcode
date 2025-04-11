# Write your MySQL query statement below
select d.name as Department, e1.name as Employee, e1.salary as Salary
from Employee e1 join Department d 
on e1.departmentId = d.id
WHERE 3 > (
    SELECT COUNT(DISTINCT(e2.salary)) 
    FROM Employee e2 
    WHERE e2.salary > e1.salary AND
    e1.departmentId = e2.departmentId
)