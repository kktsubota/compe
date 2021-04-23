n, k = map(int, input().split())

a = n
for i in range(k):
    s = "".join(sorted(str(a)))
    a = int(s[::-1]) - int(s)

print(a)
