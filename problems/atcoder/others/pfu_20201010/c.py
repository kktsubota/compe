import bisect


n = int(input())
p = list(map(int, input().split()))
values = list(range(0, max(p) + 2))

for i, v in enumerate(p):
    index = bisect.bisect(values, v)
    if value == values[index]:
        pass
    if i == 0:
        min(ans, value)
