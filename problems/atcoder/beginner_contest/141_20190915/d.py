import heapq


n, m = map(int, input().split())
costs = list(map(lambda c: -int(c), input().split()))
heapq.heapify(costs)

for i in range(m):
    v = heapq.heappop(costs)
    v = v / 2
    # print(v)
    heapq.heappush(costs, v)


print(sum(map(lambda c: int(-c), costs)))
