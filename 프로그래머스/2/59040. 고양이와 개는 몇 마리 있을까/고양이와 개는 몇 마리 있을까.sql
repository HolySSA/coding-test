-- 코드를 입력하세요
SELECT ANIMAL_TYPE,
       COUNT(ANIMAL_TYPE) as count
FROM ANIMAL_INS 
WHERE ANIMAL_TYPE in ("Cat", "Dog")
GROUP BY 1
ORDER BY 1