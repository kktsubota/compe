import decimal
import heapq


n = int(input())
vs = list(map(int, input().split()))

heapq.heapify(vs)

# print(vs)
while len(vs) != 1:
    v1 = heapq.heappop(vs)
    v2 = heapq.heappop(vs)
    v = decimal.Decimal(v1) + decimal.Decimal(v2)
    v = v / decimal.Decimal(2)
    
    heapq.heappush(vs, v)

print(vs[0])
