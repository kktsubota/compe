n, k = map(int, input().split())

# 2 ** 30 > 10^9
ans = 0
while n != 0:
    n = n // k
    ans += 1

print(ans)
