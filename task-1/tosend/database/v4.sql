SELECT MIN(avg_ball) FROM (SELECT avg_ball FROM students WHERE avg_ball BETWEEN 4 AND 4.8)
UNION ALL 
SELECT MAX(avg_ball) FROM (SELECT AVG(avg_ball) FROM students WHERE avg_ball > 4.8);