n, d = map(int, input().split())

r = 2 * d + 1
if n % r == 0:
    print(n // r)
else:
    print(n // r + 1)