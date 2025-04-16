# Write your MySQL query statement below
select p.product_name, sum(n.unit) as unit
from Products p join 
(select * from Orders where date_format(order_date,'%Y-%m')='2020-02') as n
on p.product_id=n.product_id
group by p.product_id having sum(n.unit)>=100 