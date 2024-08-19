-- 코드를 입력하세요
SELECT DATE_FORMAT(SALES_DATE, '%Y-%m-%d'),
       PRODUCT_ID,
       USER_ID,
       SALES_AMOUNT
FROM ONLINE_SALE
WHERE MONTH(SALES_DATE) = '03'
UNION
SELECT DATE_FORMAT(SALES_DATE, '%Y-%m-%d'),
       PRODUCT_ID,
       NULL AS USER_ID,
       SALES_AMOUNT
FROM OFFLINE_SALE 
WHERE MONTH(SALES_DATE) = '03'
ORDER BY 1, 2, 3
