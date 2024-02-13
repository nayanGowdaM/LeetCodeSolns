# Write your MySQL query statement below
SELECT E.employee_id,E.name, T.reports_count,T.average_age
FROM Employees E
JOIN 
(SELECT reports_to  AS employee_id, COUNT(*) AS  reports_count, ROUND( AVG(age),0) AS average_age
FROM Employees
WHERE reports_to IS NOT NULL
GROUP BY reports_to) AS T
ON E.employee_id = T.employee_id
ORDER BY E.employee_id