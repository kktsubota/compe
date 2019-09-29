n, m = map(int, input().split())
dp = [[0] * n for i in range(n)]

for i in range(m):
    a, b = map(int, input().split())
    c = list(map(int, input().split()))

