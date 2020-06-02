from collections import defaultdict


n = int(input())
Ss = list()
Ps = list()
p_dict = defaultdict(list)
for i in range(n):
    s, p = input().split()
    Ss.append(s)
    Ps.append(int(p))
    p_dict[s].append((int(p), i + 1))

s_unique = sorted(list(set(Ss)))
for s in s_unique:
    # sort by value
    pairs = sorted(p_dict[s], key=lambda e: e[0], reverse=True)
    for pair in pairs:
        print(pair[1])

