# Write your MySQL query statement below
select contest_id ,  ROUND(IFNULL( COUNT(r.user_id)/(select count(*) from Users)*100 , 0), 2) AS percentage 
from  Register r
group by contest_id
order by  percentage desc , contest_id ;