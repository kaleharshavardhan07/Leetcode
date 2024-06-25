# Write your MySQL query statement below
with prod as( 
select count( product_key) as cont
from Product)
select customer_id  
from Customer c
group by customer_id 
having count(distinct c.product_key)=(select cont from prod);