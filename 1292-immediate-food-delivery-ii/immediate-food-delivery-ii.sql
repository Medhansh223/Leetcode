SELECT 
    ROUND(SUM(IF(order_date = customer_pref_delivery_date, 1, 0)) * 100.0 / COUNT(customer_id), 2) AS immediate_percentage
FROM Delivery
WHERE (customer_id, order_date) IN 
    (SELECT customer_id, MIN(order_date) 
     FROM Delivery 
     GROUP BY customer_id);