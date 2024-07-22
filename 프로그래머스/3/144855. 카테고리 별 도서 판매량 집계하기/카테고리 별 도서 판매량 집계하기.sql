-- 코드를 입력하세요
SELECT B.CATEGORY,
       SUM(BS.SALES) as TOTAL_SALES
FROM BOOK_SALES BS INNER JOIN BOOK B ON BS.BOOK_ID=B.BOOK_ID
WHERE MONTH(SALES_DATE) = '1'
GROUP BY 1
ORDER BY 1