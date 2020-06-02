import itertools
import math


n = int(input())
xs = list()
ys = list()
for i in range(n):
    x, y = map(int, input().split())
    xs.append(x)
    ys.append(y)

costs = list()
indices = itertools.permutations(range(n))
for index in indices:
    cost = 0.0
    for i, j in zip(index[:-1], index[1:]):
        d2 = (xs[j] - xs[i]) ** 2 + (ys[j] - ys[i]) ** 2
        cost += math.sqrt(d2)
    costs.append(cost)

print(sum(costs) / len(costs))
