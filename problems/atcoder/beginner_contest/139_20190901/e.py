from collections import deque


n = int(input())

vs_table = list()
for i in range(n):
    row = list(map(int, input().split()))
    vs_row = [(i, r - 1) for r in row]
    vs_row = deque(vs_row)
    vs_table.append(vs_row)

# print(vs_table)
schedule = set()


for i in range(n):
    schedule.add(vs_table[i].popleft())


ans = 0
while len(schedule) != 0:
    # print(schedule)
    schedule_rm = set()
    for sc in schedule:
        if (sc[1], sc[0]) in schedule:
            schedule_rm.add(sc)
            schedule_rm.add((sc[1], sc[0]))
    
    schedule = schedule - schedule_rm
    if len(schedule_rm) == 0:
        ans = -1
        break
    ans += 1

    for sc in schedule_rm:
        if len(vs_table[sc[0]]) != 0:
            schedule.add(vs_table[sc[0]].popleft())
            
print(ans)
