-- https://leetcode.com/problems/find-followers-count/description/?envType=study-plan-v2&envId=top-sql-50
SELECT user_id , COUNT(follower_id) as followers_count
FROM Followers GROUP BY user_id ORDER BY user_id ASC;