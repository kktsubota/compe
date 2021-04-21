import numpy as np


class GroupInt:
    def __init__(self, arr):

    def add(self, v):
        
n = int(input())
A = np.array(list(map(int, input.split())))

ans = 0
for i in range(n):
    diff = (A[i] - A[:i-1])
    ans += (diff ** 2).sum()

print(ans)

