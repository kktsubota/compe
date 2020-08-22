n = int(input())
a = list(map(int, input().split()))

ans = 0
v_max = a[0]
for v in a:
    if v < v_max:
        ans += (v_max - v)
    else:
        v_max = v
print(ans)
