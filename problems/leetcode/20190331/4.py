from typing import List


class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        M, N = len(A), len(A[0])
        conn_flag = [[False for i in range(N)] for i in range(M)]
        for i in range(M):
            if A[i][0] == 1:
                conn_flag[i][0] = True
            
            if A[i][N - 1] == 1:
                conn_flag[i][N - 1] = True
        
        for j in range(N):
            if A[0][j] == 1:
                conn_flag[0][j] = True
            
            if A[M - 1][j] == 1:
                conn_flag[M - 1][j] = True

    def is_connect(self, A: List[List[int]], i: int, j: int) -> int:
        A[i][j]


A = [[0, 0, 0, 0],
     [1, 0, 1, 0],
     [0, 1, 1, 0],
     [0, 0, 0, 0]]
Solution().numEnclaves(A)