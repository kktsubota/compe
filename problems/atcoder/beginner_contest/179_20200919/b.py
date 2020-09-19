n = int(input())

def find(d):
    pp = False
    p = False
    for d1, d2 in d:
        now = (d1 == d2)
        if pp and p and now:
            return True
        pp = p
        p = now

    return False

d = list()
for i in range(n):
    d1, d2 = map(int, input().split())
    d.append((d1, d2))

if find(d):
    print('Yes')
else:
    print('No')
