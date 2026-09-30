-- 코드를 작성해주세요
SELECT upgraded.ITEM_ID, upgraded.ITEM_NAME, upgraded.RARITY
FROM ITEM_INFO ii
INNER JOIN ITEM_TREE it
    ON ii.ITEM_ID = it.PARENT_ITEM_ID
INNER JOIN ITEM_INFO upgraded
    ON it.ITEM_ID = upgraded.ITEM_ID
WHERE ii.RARITY = 'RARE'
ORDER BY upgraded.ITEM_ID DESC;