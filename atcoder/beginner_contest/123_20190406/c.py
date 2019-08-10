n = int(input())
a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())

limits = list()
limits.append(a)
limits.append(b)
limits.append(c)
limits.append(d)
limits.append(e)

min_v, min_i = limits[0], 0
for i, limit in enumerate(limits):
    if min_v > limit:
        min_v = limit
        min_i = i
if min_v >= n:
    time = 5
elif n % min_v == 0:
    time = 5 + n // min_v - 1
else:
    time = 5 + n // min_v

print(time)
