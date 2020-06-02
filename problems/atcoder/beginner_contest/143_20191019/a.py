a, b = map(int, input().split())

ans = a - b * 2
if ans >= 0:
    print(ans)
else:
    print(0)