-- 코드를 입력하세요
SELECT RI.REST_ID,
       RI.REST_NAME,
       RI.FOOD_TYPE,
       RI.FAVORITES,
       RI.ADDRESS,
       ROUND(AVG(RR.REVIEW_SCORE), 2) AS SCORE
FROM REST_INFO RI INNER JOIN REST_REVIEW RR ON RI.REST_ID=RR.REST_ID
GROUP BY RI.REST_ID
HAVING RI.ADDRESS LIKE '서울%'
ORDER BY 6 DESC, 4 DESC