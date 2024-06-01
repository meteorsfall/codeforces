import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n, p, l, t = map(int, input().split())
    num_tasks = (n - 1)//7 + 1
    day_p = l + t*2
    max_two_task_day = num_tasks//2
    two_task_day = min(math.ceil(p/day_p), max_two_task_day)
    total = two_task_day*day_p
    days_working = two_task_day
    if total < p and (num_tasks % 2 == 1):
        days_working += 1
        total += l
        total += t
    if total < p:
        lesson_days = math.ceil((p - total)/l)
        days_working += lesson_days
        total += lesson_days*l
    print(n - days_working)