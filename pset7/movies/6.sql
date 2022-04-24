SELECT ROUND(AVG(ratings.rating),2) FROM movies
INNER JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.year = 2012;