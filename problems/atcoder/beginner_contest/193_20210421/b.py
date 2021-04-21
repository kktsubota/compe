import numpy as np


n = int(input())
A = np.empty((n,), dtype=int)
P = np.empty((n,), dtype=int)
X = np.empty((n,), dtype=int)

for i in range(n):
    a, p, x = map(int, input().split())
    A[i] = a
    P[i] = p
    X[i] = x
    
X = X - A
if (X > 0).sum() == 0:
    print(-1)
else:
    print(P[X > 0].min())