SELECT AVG(avg_ball) AS OkAverage FROM students WHERE avg_ball BETWEEN 4 AND 4.8 
UNION ALL
SELECT AVG(avg_ball) AS BotAverage FROM students WHERE avg_ball > 4.8;