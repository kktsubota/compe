a, b, c, k = map(int, input().split())

ans = 0
num = min(a, k)
ans += num
k -= num

if k == 0:
    print(ans)

else:
    k -= b
    if k <= 0:
        print(ans)
    else:
        print(ans - k)
    