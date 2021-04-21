import numpy as np


n = int(input())
A = list()
B = list()
for i in range(n):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

A = np.array(A)
B = np.array(B)

idx_a = np.argsort(A)
idx_b = np.argsort(B)

if idx_a[0] != idx_b[0]:
    print(max(A[idx_a[0]], B[idx_b[0]]))

else:
    t1 = A[idx_a[0]] + B[idx_b[0]]
    t2 = max(A[idx_a[0]], B[idx_b[1]])
    t3 = max(A[idx_a[1]], B[idx_b[0]])
    print(min(t1, t2, t3))

