# Write your MySQL query statement below
SELECT  ei.unique_id , e.name   FROM
Employees as e
LEFT JOIN EmployeeUNI as ei
ON e.id = ei.id;

