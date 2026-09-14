# just renaming/reassigning the IDs in the output
select 
    (case 
        when (id % 2 = 1) and (id + 1 in (select id from Seat)) 
            then id+1
        when (id % 2 = 0) 
            then id - 1
        else
            id
    end) as id, 
    student
from Seat
order by id

-- IF id is odd AND next ID exists
--     use id + 1
-- ELSE IF id is even
--     use id - 1
-- ELSE
--     use id

-- Original             Calculated

-- 1 Alice  ──────────→  2 Alice
-- 2 Bob    ──────────→  1 Bob

-- 3 Charlie──────────→  4 Charlie
-- 4 David  ──────────→  3 David

-- 5 Eve    ──────────→  5 Eve