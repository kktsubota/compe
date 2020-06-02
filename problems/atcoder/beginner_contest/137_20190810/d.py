from collections import defaultdict
import heapq


n, m = map(int, input().split())
jobs = defaultdict(list)

for i in range(n):
    a, b = map(int, input().split())
    jobs[a].append(-b)


ans = 0
jobs_h = list()
for i in range(1, m + 1):
    for job in jobs[i]:
        heapq.heappush(jobs_h, job)

    if len(jobs_h) != 0:
        # b -> -b -> b
        value = heapq.heappop(jobs_h)
        ans -= value

print(ans)