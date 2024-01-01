SELECT people.name
    FROM stars

 JOIN movies ON movies.id = stars.movie_id
 JOIN people ON people.id = stars.person_id

 WHERE movies.title IN
    (SELECT movies.title
        FROM stars

     JOIN movies ON movies.id = stars.movie_id
     JOIN people ON people.id = stars.person_id

     WHERE people.name = 'Kevin Bacon' AND people.birth = 1958
     )
    AND NOT people.name = 'Kevin Bacon';
