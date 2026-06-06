-- 코드를 작성해주세요
SELECT fi.ID, fni.FISH_NAME, fi.LENGTH
FROM FISH_INFO fi
JOIN FISH_NAME_INFO fni ON fi.FISH_TYPE = fni.FISH_TYPE
WHERE (fi.FISH_TYPE, fi.LENGTH) IN (
    -- 1. 물고기 종류별로 가장 긴 길이를 찾는 서브쿼리
    SELECT FISH_TYPE, MAX(LENGTH)
    FROM FISH_INFO
    GROUP BY FISH_TYPE
)
-- 2. 마지막으로 ID 기준 오름차순 정렬
ORDER BY fi.ID ASC;