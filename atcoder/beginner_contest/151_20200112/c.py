n, m = map(int, input().split())
ps, ss = list(), list()
for i in range(m):
    p, s = input().split()
    p = int(p) - 1
    ps.append(p)
    ss.append(s)


num = [0 for i in range(n)]
correct, penalty = 0, 0

for i in range(m):
    p, s = ps[i], ss[i]
    if num[p] == -1:
        continue

    num[p] += 1
    if s == 'AC':
        correct += 1
        penalty += (num[p] - 1)
        num[p] = -1

print(correct, penalty)        
