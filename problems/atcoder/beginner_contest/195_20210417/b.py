a, b, w = map(int, input().split())

values = list()
for i in range(1, 1000001):
    if (a * i) <= (w * 1000) <= (b * i):
        values.append(i)

if len(values) == 0:
    print("UNSATISFIABLE")
else:
    print(min(values), max(values))
