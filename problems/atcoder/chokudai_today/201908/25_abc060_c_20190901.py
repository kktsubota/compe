import bisect


N, T = map(int, input().split())
ts = list(map(int, input().split()))

ans = 0
start = 0
end = 0

for i, t in enumerate(ts):
    if i == 0:
        start, end = t, t + T
        continue

    # assert start <= t
    if t <= end:
        end = t + T
    else:
        ans += (end - start)
        start, end = t, t + T

ans += (end - start)
print(ans)
