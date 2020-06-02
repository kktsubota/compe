n, x = map(int, input().split())
Ls = list(map(int, input().split()))

ans = 1
d = 0
for i in range(n):
    d += Ls[i]
    if d <= x:
        ans += 1
    
    else:
        break

print(ans)