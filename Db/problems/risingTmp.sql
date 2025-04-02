--https://leetcode.com/problems/rising-temperature/?envType=study-plan-v2&envId=top-sql-50
SELECT w1.id 
FROM weather w1 
JOIN weather w2 ON (w1.recordDate - w2.recordDate) = 1
WHERE w1.temperature > w2.temperature;