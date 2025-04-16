# Write your MySQL query statement below
(select u.name as results from MovieRating m join Users u on m.user_id=u.user_id group by u.user_id order by count(m.rating) desc, u.name limit 1)
union all
(select mo.title as results from Movies mo join MovieRating m on mo.movie_id=m.movie_id where date_format(m.created_at,'%Y-%m')='2020-02' group by mo.title
order by avg(m.rating) desc, mo.title limit 1)