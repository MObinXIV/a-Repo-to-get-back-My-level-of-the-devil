--https://leetcode.com/problems/customers-who-bought-all-products/solutions/3608247/simple-solution-with-two-line-query/?envType=study-plan-v2&envId=top-sql-50
SELECT customer_id FROM customer
group by customer_id
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(DISTINCT product_key) FROM product);
