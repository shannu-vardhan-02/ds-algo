# Write your MySQL query statement below
select st.machine_id,
round(avg(en.timestamp - st.timestamp), 3) as processing_time

from Activity as st

join Activity as en
on st.machine_id = en.machine_id and st.process_id = en.process_id

where st.activity_type = 'start' and en.activity_type = 'end'

group by st.machine_id