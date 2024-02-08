# Write your MySQL query statement below
SELECT contest_id,ROUND( 100*COUNT(*) / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Register R
LEFT JOIN Users U ON 
    U.user_id = R.user_id
GROUP BY contest_id
ORDER BY percentage DESC,contest_id