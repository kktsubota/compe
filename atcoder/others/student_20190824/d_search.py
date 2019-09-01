n = 5
edges = list()
for i in range(n):
    for j in range(i + 1, n):
        edges.append((i, j))
        edges