n, k = map(int, input().split())
h = list(map(int, input().split()))
h = sorted(h)

if len(h) <= k:
    print(0)
else:
    if k == 0:
        print(sum(h))
    else:
        print(sum(h[:-k]))
        