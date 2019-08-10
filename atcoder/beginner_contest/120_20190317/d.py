def get_groups(n_lands, edges):
    # 1 .. n_lands
    return groups

# N, M
n_lands, n_bridges = map(int, input().split())
# A, B
edges = list()
for i in range(n_bridges):
    edge = list(map(int, input().split()))
    edges.append(edge)

# init
group = {i + 1 for i in range(n_lands)}
groups = {group}

for i in range(n_bridges):
    groups = get_groups()
    # split
    if len(groups) == 2:
        len(groups[0]) * len(groups[1])