SELECT e.employee_id,
       e.name,
       COUNT(c.employee_id) AS reports_count,
       ROUND(AVG(c.age)) AS average_age
FROM Employees e
INNER JOIN Employees c ON e.employee_id = c.reports_to
GROUP BY e.employee_id, e.name
ORDER BY e.employee_id;
