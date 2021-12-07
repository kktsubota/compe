from collections import defaultdict


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

n, m = map(int, input().split())
edge = defaultdict(list)
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edge[a].append(b)
    edge[b].append(a)

answers = list()
union_find = UnionFind(n)
group_size = 0
for i in range(n):
    if i == 0:
        answers.append(0)
        continue
    
    # add n-i node
    group_size += 1
    for to in edge[n - i]:
        # have not been added
        if to <= (n - i):
            continue

        # will merge
        if union_find.find(n - i) != union_find.find(to):
            group_size -= 1

        union_find.union(n - i, to)
    answers.append(group_size)

for ans in answers[::-1]:
    print(ans)

