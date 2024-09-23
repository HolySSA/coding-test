-- 코드를 입력하세요
-- 0을 포함해줘야 하기 때문에 SET을 사용해야 한다.
SET @HOUR = -1;
SELECT (@HOUR := @HOUR +1) AS HOUR,
       (
           SELECT COUNT(HOUR(DATETIME)) 
           FROM ANIMAL_OUTS 
           WHERE HOUR(DATETIME)=@HOUR
       ) AS COUNT 
FROM ANIMAL_OUTS
WHERE @HOUR < 23;