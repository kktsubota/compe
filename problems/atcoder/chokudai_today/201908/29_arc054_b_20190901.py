import math

P = float(input())
a = 1.5 / math.log(2)
ans = a * (1 - math.log(a) + math.log(P))

x = 1.5 * (math.log2(P) - math.log2(a))
if x < 0:
    print(P)
else:
    print(ans)
