-- https://leetcode.com/problems/product-sales-analysis-i/?envType=study-plan-v2&envId=top-sql-50
SELECT product.product_name ,sales.year , sales.price 
FROM sales 
JOIN product
ON sales.product_id=product.product_id;