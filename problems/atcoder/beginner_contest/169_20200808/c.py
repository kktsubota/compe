a, b = input().split()
a = int(a)
if '.' in b:
    i, f = b.split('.')
    b = int(i) * 100 + int(f)

else:
    b = int(b) * 100

ans = a * b // 100
print(ans)
