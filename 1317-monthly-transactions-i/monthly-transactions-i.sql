-- -- Add the new column to the table
-- ALTER TABLE Transactions
-- ADD COLUMN months VARCHAR(7);

-- -- Update the new column based on existing data
-- UPDATE Transactions
-- SET months = CONCAT(YEAR(date_column), '-', LPAD(MONTH(date_column), 2, '0'));

-- -- Select the required information
-- SELECT
--     months AS month,
--     country,
--     COUNT(*) AS trans_count,
--     SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
--     SUM(amount) AS trans_total_amount,
--     SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
-- FROM
--     Transactions
-- GROUP BY
--     country, months;


SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    COUNT(*) AS trans_count,
    SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
FROM
    Transactions
GROUP BY
    month, country
ORDER BY
    month, country;