# Write your MySQL query statement below
select eun.unique_id, e.name from EmployeeUNI eun right join Employees e on eun.id = e.id 