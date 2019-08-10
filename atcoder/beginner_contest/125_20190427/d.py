N = int(input())
As = list(map(int, input().split()))

n_neg = 0
for A in As:
    if A < 0:
        n_neg += 1

Bs = list(map(abs, As))
if n_neg % 2 == 0:
    ans = sum(Bs)

else:
    Bs = sorted(Bs)
    Bs[0] = -Bs[0]
    ans = sum(Bs)
print(ans)