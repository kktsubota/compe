import numpy as np


N, M = map(int, input().split())
A, B = list(), list()
for i in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)
A = np.array(A)
B = np.array(B)

n_bins = 0
cost = 0
indices = np.argsort(A)
for idx in indices:
    # enough bins @idx
    if n_bins + B[idx] > M:
        cost += A[idx] * (M - n_bins)
        break
    # buy all bins
    else:
        n_bins += B[idx]
        cost += A[idx] * B[idx]
print(cost)