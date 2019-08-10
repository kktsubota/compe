a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())

times = list()
times.append(a)
times.append(b)
times.append(c)
times.append(d)
times.append(e)

time_sum = 0
small = 10
for time in times:
    if time % 10 == 0:
        time_sum += time
    else:
        time_sum += (time // 10 + 1) * 10
        small = min(small, time % 10)
print(time_sum - 10 + small)