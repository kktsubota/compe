n, k = map(int, input().split())
ps = list(map(int, input().split()))

# expectancy 1 + 2 + ... + p / p = p * (p + 1) / p / 2 = (p + 1) / 2

sum_max = 0
for i in range(k - 1, n):
    if i == k - 1:
        sum_now = sum(ps[:i + 1])
    else:
        sum_now = sum_now + ps[i] - ps[i - k]
    sum_max = max(sum_max, sum_now)

print((sum_max + k) / 2)