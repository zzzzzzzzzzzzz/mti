SELECT COUNT(id_student,avg_ball) FROM students WHERE avg_ball BETWEEN 4 AND 4.8 
UNION ALL
SELECT COUNT(id_student,avg_ball) FROM students WHERE avg_ball > 4.8;