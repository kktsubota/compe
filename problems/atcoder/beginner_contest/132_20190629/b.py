n = int(input())
ps = list(map(int, input().split()))

ans = 0
for i in range(1, n - 1):
    window = (ps[i-1], ps[i], ps[i+1])
    if ps[i] != min(window) and ps[i] != max(window):
        ans += 1

print(ans)