M, D = map(int, input().split())

ans = 0
for m in range(1, M+1):
    for d in range(1, D+1):
        d_10 = d // 10
        d_1 = d % 10
        if d_10 < 2 or d_1 < 2:
            continue
        if d_10 * d_1 == m:
            ans += 1

print(ans)
