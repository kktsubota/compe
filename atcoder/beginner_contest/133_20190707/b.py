n, d = map(int, input().split())
xs = list()
for i in range(n):
    x = list(map(int, input().split()))
    xs.append(x)


def is_valid(k):
    for i in range(200):
        m = i ** 2
        if k == m:
            return True
        elif k < m:
            return False
    
    return False


ans = 0
for i in range(n):
    for j in range(i + 1, n):
        s = 0
        for e in range(d):
            s += (xs[i][e] - xs[j][e]) ** 2
        if is_valid(s):
            ans += 1

print(ans)