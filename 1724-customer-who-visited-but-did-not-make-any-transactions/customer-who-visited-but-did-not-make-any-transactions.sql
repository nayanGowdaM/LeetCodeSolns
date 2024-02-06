# Write your MySQL query statement below
SELECT distinct customer_id, COUNT(*) AS count_no_trans FROM Visits
WHERE visit_id not in(
    SELECT visit_id FROM Transactions
)
GROUP BY customer_id;
