import numpy as np


N, M, C = map(int, input().split())
B = np.fromiter(map(int, input().split()), dtype=int)
As = list()
for i in range(N):
    a = np.fromiter(map(int, input().split()), dtype=int)
    As.append(a)
As = np.vstack(As)
print(int(np.sum(As.dot(B) + C > 0)))

