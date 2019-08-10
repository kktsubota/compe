import queue


H, W = map(int, input().split())
A = list()
for i in range(H):
    A_row = input()
    A.append(A_row)


black_mass = queue.Queue()

count = 0
is_checked = set()
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            black_mass.put((count, i, j))

while not black_mass.empty():
    c, i, j = black_mass.get()
    if (i, j) in is_checked:
        continue
    else:
        is_checked.add((i, j))
        count = c
        # print(c, i, j)
    if i >= 1 and (i - 1, j) not in is_checked:
        black_mass.put((count + 1, i - 1, j))    
    if j >= 1 and (i, j - 1) not in is_checked:
        black_mass.put((count + 1, i, j - 1))
    if i < H - 1 and (i, j + 1) not in is_checked:
        black_mass.put((count + 1, i + 1, j))
    if j < W - 1 and (i, j + 1) not in is_checked:
        black_mass.put((count + 1, i, j + 1))

print(count)