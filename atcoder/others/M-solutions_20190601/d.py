from collections import defaultdict, OrderedDict


N = int(input())
As, Bs = list(), list()

node_dict = defaultdict(list)

for _ in range(N - 1):
    a, b = map(int, input().split())
    a = a - 1
    b = b - 1
    As.append(a)
    Bs.append(b)

    node_dict[a].append(b)
    node_dict[b].append(a)

Cs = list(map(int, input().split()))
Cs = sorted(Cs)

node_list = sorted(node_dict.items(), key=lambda kv: len(kv[1]))

Ds = [0 for i in range(len(Cs))]
for i, (node, _) in enumerate(node_list):
    Ds[node] = Cs[i]

score = 0
for a, b in zip(As, Bs):
    score += min(Ds[a], Ds[b])

print(score)
print(' '.join(map(str, Ds)))
