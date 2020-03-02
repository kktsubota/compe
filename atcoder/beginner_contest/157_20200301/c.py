n, m = map(int, input().split())
ss = list()
cs = list()
for i in range(m):
    s, c = map(int, input().split())
    ss.append(s)
    cs.append(c)

if n != 1:
    data_range = range(10 ** (n - 1), 10 ** n)
else:
    data_range = range(0, 10)


def is_ok(i):
    for s, c in zip(ss, cs):
        if int(str(i)[s - 1]) != c:
            return False
    return True

for i in data_range:
    if is_ok(i):
        print(i)
        break
else:
    print('-1')
