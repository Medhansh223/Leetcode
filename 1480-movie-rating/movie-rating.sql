# Write your MySQL query statement below
(SELECT name as results
from Users u join MovieRating m
on u.user_id = m.user_id
group by u.user_id
order by count(m.rating) desc, u.name 
limit 1)

UNION ALL

(SELECT title as results
from Movies u join MovieRating m
on u.movie_id = m.movie_id
where date_format(m.created_at,'%Y-%m') = '2020-02'
group by u.title
order by AVG(m.rating) desc, u.title
limit 1)