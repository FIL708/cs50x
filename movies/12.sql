SELECT movies.title
    FROM stars

 JOIN movies ON movies.id = stars.movie_id
 JOIN people ON people.id = stars.person_id

 WHERE people.name = 'Bradley Cooper'
 AND movies.title IN
    (SELECT movies.title
        FROM stars
     JOIN movies ON movies.id = stars.movie_id
     JOIN people ON people.id = stars.person_id

     WHERE people.name = 'Jennifer Lawrence');
