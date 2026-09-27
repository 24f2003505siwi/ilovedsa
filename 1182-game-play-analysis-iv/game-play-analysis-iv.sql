# Write your MySQL query statement below
select round(count(a1.player_id) / (select count(distinct(player_id)) from activity), 2) as fraction
from (
    select player_id, min(event_date) as event_date
    from activity group by player_id
) a1
join activity a2
on a1.player_id = a2.player_id and datediff(a2.event_date, a1.event_date) = 1