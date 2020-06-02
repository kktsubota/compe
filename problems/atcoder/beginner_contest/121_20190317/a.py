import numpy as np


H, W = map(int, input().split())
h, w = map(int, input().split())
board = np.ones((H, W), dtype=int)
board[0:h] = 0
board[:, 0:w] = 0
print(board.sum())