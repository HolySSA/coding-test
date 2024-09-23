-- 0을 포함해줘야 하기 때문에 'SET'을 사용해야 한다. (단순한 GROUP BY 불가)
-- SET은 어떤 변수에 특정 값을 할당할때 쓰는 명령어.
-- SET 사용시 대입 연산자에만 '='를 사용하고 그 외에는 ':=' 사용

/* 처음 통과했던 풀이
SET @HOUR = -1;
SELECT (@HOUR := @HOUR + 1) AS 'HOUR',
       IFNULL(BO.COUNT, 0) AS 'COUNT'
FROM ANIMAL_OUTS AO LEFT OUTER JOIN (
    SELECT HOUR(DATETIME) AS 'HOUR',
           COUNT(1) AS 'COUNT'
    FROM ANIMAL_OUTS
    WHERE HOUR(DATETIME) < 24
    GROUP BY 1
    ORDER BY 1
) BO ON @HOUR + 1 = BO.HOUR
WHERE @HOUR < 23;
*/

-- select 서브쿼리 풀이
SET @HOUR = -1;
SELECT (@HOUR := @HOUR + 1) AS 'HOUR',
       (
           SELECT COUNT(HOUR(DATETIME)) 
           FROM ANIMAL_OUTS 
           WHERE HOUR(DATETIME)=@HOUR
       ) AS COUNT 
FROM ANIMAL_OUTS
WHERE @HOUR < 23;
