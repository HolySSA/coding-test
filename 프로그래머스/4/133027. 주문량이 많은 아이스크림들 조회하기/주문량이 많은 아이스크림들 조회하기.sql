-- 코드를 입력하세요
SELECT FH.FLAVOR
FROM FIRST_HALF FH INNER JOIN (
                               SELECT FLAVOR,
                                      SUM(TOTAL_ORDER) AS JULY_TOTAL_ORDER
                               FROM JULY
                               GROUP BY FLAVOR
                              ) J
                   ON FH.FLAVOR = J.FLAVOR
ORDER BY TOTAL_ORDER + JULY_TOTAL_ORDER DESC
LIMIT 3;