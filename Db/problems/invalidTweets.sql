--https://leetcode.com/problems/invalid-tweets/submissions/1594801761/?envType=study-plan-v2&envId=top-sql-50
SELECT tweet_id  FROM  tweets
WHERE LENGTH(content)>15;