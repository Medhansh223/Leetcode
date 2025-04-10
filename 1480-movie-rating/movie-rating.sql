(select name as results
from Users u join MovieRating m using(user_id)
group by u.user_id
order by count(m.rating) desc,u.name limit 1)

UNION ALL

(select title as results
from Movies join MovieRating using(movie_id)
where date_format(created_at,'%Y-%m')='2020-02' 
group by title order by avg(rating) desc,title limit 1)