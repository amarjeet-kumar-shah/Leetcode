-- Write your PostgreSQL query statement below

with cte as (
select *, 
id - row_number() over() as diff
from stadium
where people >=100
)

select id, visit_date, people
from cte
where diff in (select diff from cte group by diff having count(*) >=3)
order by visit_date