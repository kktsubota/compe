import numpy as np


N, Q = map(int, input().split())
s = input()
t_list, d_list = list(), list()
for i in range(Q):
    t, d = map(int, input().split())
    t_list.append(t)
    d_list.append(d)


cache = -np.ones((Q, N + 2), dtype=int)
cache[:, 1:N+1] = 1
cache[:, 0] = 0
cache[:, N+1] = 1

def func(q, n, d):
    