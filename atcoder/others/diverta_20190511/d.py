N = int(input())

ans = 0
for i in range(1, 10 ** 6 + 1):
    if i >= N:
        break
    if N % i == 0:
        m = N // i - 1
        if m > i:
            ans += m
            # print(i, m)

print(ans)