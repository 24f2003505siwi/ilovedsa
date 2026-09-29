# Write your MySQL query statement below
select d.name as department, e.name as employee, e.salary
from department d join employee e on e.departmentId = d.id
where 3 > (
    select count(distinct(salary)) from employee e1 
    join department d1 on e1.departmentId = d1.id
    where e1.salary > e.salary and e1.departmentid = e.departmentid
)