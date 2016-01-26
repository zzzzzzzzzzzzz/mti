SELECT MID(fio,1,1), AVG(avg_ball) FROM students 
GROUP BY MID(fio,1,1);