# Write your MySQL query statement below
-- select max(salary) as SecondHighestSalary from Employee where salary<(select max(salary) from Employee)

select max(e1.salary) as SecondHighestSalary from Employee e1 join Employee e2 where e1.salary<e2.salary