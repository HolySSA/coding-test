-- 코드를 입력하세요
SELECT DR_NAME,
       DR_ID,
       MCDP_CD,
       DATE_FORMAT(HIRE_YMD, "%Y-%m-%d") as HIRE_YMD
FROM DOCTOR 
WHERE MCDP_CD in ("CS", "GS")
ORDER BY 4 DESC, 1