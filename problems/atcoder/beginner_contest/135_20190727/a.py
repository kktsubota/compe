a, b = map(int, input().split())

# k = (a + b) // 2
if (a + b) % 2 == 0:
    print((a + b) // 2)
else:
    print('IMPOSSIBLE')
