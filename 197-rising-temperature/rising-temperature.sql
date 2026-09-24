# Write your MySQL query statement below
SELECT tdy.id
FROM Weather tdy
JOIN Weather ydy
ON DATEDIFF(tdy.recordDate, ydy.recordDate) = 1
WHERE tdy.temperature > ydy.temperature
