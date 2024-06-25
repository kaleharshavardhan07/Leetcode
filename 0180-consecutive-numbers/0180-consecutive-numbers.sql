SELECT x.num AS ConsecutiveNums
FROM Logs x 
WHERE EXISTS (
    SELECT 1 
    FROM Logs y
    WHERE y.id = x.id + 1 AND y.num = x.num
) AND EXISTS (
    SELECT 1
    FROM Logs z
    WHERE z.id = x.id + 2 AND z.num = x.num
)
GROUP BY x.num;
