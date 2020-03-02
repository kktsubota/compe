import numpy as np


n = int(input())
a = np.fromiter(map(int, input().split()), dtype=int)
if len(np.unique(a)) == len(a):
    print('YES')
else:
    print('NO')
    