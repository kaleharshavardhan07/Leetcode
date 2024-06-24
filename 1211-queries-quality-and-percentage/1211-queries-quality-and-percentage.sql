WITH QueryQuality AS (
    SELECT 
        query_name,
        AVG(rating * 1.0 / position) AS quality
    FROM 
        Queries
    GROUP BY 
        query_name
),
PoorQueryCount AS (
    SELECT 
        query_name,
        COUNT(*) AS total_queries,
        SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) AS poor_queries
    FROM 
        Queries
    GROUP BY 
        query_name
)
SELECT 
    qq.query_name,
    ROUND(qq.quality, 2) AS quality,
    ROUND((pq.poor_queries * 100.0 / pq.total_queries), 2) AS poor_query_percentage
FROM 
    QueryQuality qq
JOIN 
    PoorQueryCount pq ON qq.query_name = pq.query_name;
