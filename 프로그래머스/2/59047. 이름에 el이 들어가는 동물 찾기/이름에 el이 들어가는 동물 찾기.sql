-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE NAME like "%EL%" and ANIMAL_TYPE = "Dog"
ORDER BY 2
