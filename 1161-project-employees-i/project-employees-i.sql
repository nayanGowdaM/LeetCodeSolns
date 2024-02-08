# Write your MySQL query statement below
SELECT project_id, ROUND( AVG(experience_years),2) AS average_years
FROM Employee E
JOIN Project P ON 
    E.employee_id = P.employee_id
GROUP BY project_id