--https://leetcode.com/problems/biggest-single-number/submissions/1590374473/?envType=study-plan-v2&envId=top-sql-50
SELECT MAX(num)AS num FROM  MyNumbers
WHERE 
num IN (SELECT num FROM MyNumbers GROUP BY num HAVING count(*)=1);

-- Merging 2 statements inside one statement , choose the max number this is main query , then 
-- get the number whose count is 1 