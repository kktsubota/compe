H, W = map(int, input().split())
A = list()
for i in range(H):
    A_row = input()
    A.append(A_row)


class Land(object):
    def __init__(self, positions):
        self.positions = set(positions)
    
    def __len__(self):
        return len(self.positions)
    
    def get_countour(self):
        pass
    
    def merge(self, land):
        if len(self.positions * land.positions) > 0:
            self.positions += land.positions

lands = list()
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            land = Land((i, j))
            lands.append(land)
