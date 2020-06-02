a, b = map(int, input().split())

# 1 + (a - 1) * x >= b
print((b - 2) // (a - 1) + 1)
