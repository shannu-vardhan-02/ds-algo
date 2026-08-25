# Write your MySQL query statement below
select e1.name

from Employee as e1

join Employee as e2
on e1.id = e2.managerId

group by e2.managerId
-- having should be used after group, so conditions bases on aggregating by group by should be used by using HAVING
having count(e2.id) >= 5



-- e1.id  e1.name    e2.id  e2.managerId
--             |---> 102 ------|
--             |  -> 103       |
-- 101 --->John|  -> 104       |-- 101
--             |  -> 105       |
--             |---> 106 ------|