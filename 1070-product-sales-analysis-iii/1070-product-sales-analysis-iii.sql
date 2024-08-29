# Write your MySQL query statement below
select p.product_id , s.year as first_year , s.quantity, s.price from Product p  inner join Sales s on p.product_id=s.product_id 
 group by s.product_id  order by s.year  ;