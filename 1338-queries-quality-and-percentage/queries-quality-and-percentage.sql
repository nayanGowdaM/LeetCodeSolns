# Write your MySQL query statement below
SELECT 
    query_name, 
    ROUND(AVG(rating / position), 2) AS quality,
    ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*) *100, 2) AS poor_query_percentage
FROM 
    Queries
WHERE 
    query_name  IS NOT NULL
GROUP BY 
    query_name;


-- select
-- query_name,
-- round(avg(cast(rating as decimal) / position), 2) as quality,
-- round(sum(case when rating < 3 then 1 else 0 end) * 100 / count(*), 2) as poor_query_percentage
-- from
-- queries
-- group by
-- query_name;