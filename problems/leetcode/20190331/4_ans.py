from typing import List


class UnionFind(object):
    def __init__(self, n):
        self.parent = {i: i for i in range(n)}
        self.rank = {i: 0 for i in range(n)}
        self.size = {i: 1 for i in range(n)}
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])

        return self.parent[x]
    
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return
        
        if self.rank[x] < self.rank[y]:
            self.parent[x] = y

        else:
            self.parent[y] = x

            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

        self.size[x] += self.size[y]
        self.size[y] = self.size[x]


    def get_size(self, x):
        return self.size[self.find(x)]


class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        M, N = len(A), len(A[0])
        def get_id(i, j):
            return i * N + j
            
        # tree[M*N] for the boundary
        tree = UnionFind(M*N + 1)
        for i in range(M):
            if A[i][0] == 1:
                tree.union(get_id(i, 0), M*N)
            
            if A[i][N - 1] == 1:
                tree.union(get_id(i, N-1), M*N)
        
        for j in range(N):
            if A[0][j] == 1:
                tree.union(get_id(0, j), M*N)
            
            if A[M - 1][j] == 1:
                tree.union(get_id(M-1, j), M*N)
        
        for i in range(1, M - 1):
            for j in range(1, N - 1):
                if A[i][j] == 1:
                    if A[i - 1][j] == 1:
                        tree.union(get_id(i, j), get_id(i - 1, j))
                    if A[i + 1][j] == 1:
                        tree.union(get_id(i, j), get_id(i + 1, j))
                    if A[i][j-1] == 1:
                        tree.union(get_id(i, j), get_id(i, j - 1))
                    if A[i][j + 1] == 1:
                        tree.union(get_id(i, j), get_id(i, j + 1))

        # remove M*N itself
        return sum([sum(A[i]) for i in range(M)]) - (tree.get_size(M*N) - 1)

A = [[0, 0, 0, 0],
     [1, 0, 1, 0],
     [0, 1, 1, 0],
     [0, 0, 0, 0]]
print(Solution().numEnclaves(A))