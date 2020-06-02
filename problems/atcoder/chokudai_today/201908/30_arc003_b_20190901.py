n = int(input())
ss = list()
for i in range(n):
    ss.append(input()[::-1])

ss = sorted(ss)
for s in ss:
    print(s[::-1])