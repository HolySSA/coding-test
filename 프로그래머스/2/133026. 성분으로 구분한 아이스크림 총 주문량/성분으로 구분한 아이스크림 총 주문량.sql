-- 코드를 입력하세요
SELECT II.INGREDIENT_TYPE,
       SUM(FH.TOTAL_ORDER) as TOTAL_ORDER
FROM FIRST_HALF FH LEFT JOIN ICECREAM_INFO II ON FH.FLAVOR=II.FLAVOR
GROUP BY 1
ORDER BY 2