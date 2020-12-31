n, q = map(int, input().split())

mod = 998244353

s = ['1' for _ in range(n)]
ls = list()
rs = list()
ds = list()
for i in range(q):
    l, r, d = input().split()
    ls.append(int(l) - 1)
    rs.append(int(r) - 1)
    ds.append(d)

for l, r, d in zip(ls, rs, ds):
    for j in range(l, r + 1):
        s[j] = d
    print(int(''.join(s)) % mod)