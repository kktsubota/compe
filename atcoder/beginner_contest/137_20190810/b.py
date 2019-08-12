k, x = map(int, input().split())

xmin = x - k + 1
xmax = x + k - 1

values = list(range(xmin, xmax + 1))
print(' '.join(map(str, values)))
