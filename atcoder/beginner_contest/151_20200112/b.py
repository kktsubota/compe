n, k, m = map(int, input().split())
A = list(map(int, input().split()))


x = m * n - sum(A)
if x > k:
    print(-1)
elif x < 0:
    print(0)
else:
    print(x)
    