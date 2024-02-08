# Write your MySQL query statement below
SELECT P.product_id, IFNULL(ROUND( SUM(P.price * S.units) / SUM(S.units), 2),0) AS average_price
FROM Prices P
LEFT JOIN  UnitsSold S ON
    P.product_id = S.product_id
    AND
    S.purchase_date >= P.start_date AND S.purchase_date <=P.end_date
GROUP BY P.product_id