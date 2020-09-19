n = int(input())

ans = 0
for a in range(1, n + 1):
    q = n // a
    r = n % a

    # a <= b
    # b: a, a+1, ..., q
    # c: ...  ,r + a, r
    if q < a:
        continue
    
    else:
        # a < b, a == b
        ans += ((q - a) * 2 + 1)
        if r == 0:
            if a == q:
                ans -= 1
            else:
                ans -= 2
        # print(a, ans)

print(ans)
