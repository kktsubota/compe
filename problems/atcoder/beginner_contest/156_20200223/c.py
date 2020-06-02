n = int(input())
X = list(map(int, input().split()))


def score(p):
    sc = 0
    for x in X:
        sc += (x - p) ** 2
    return sc


scores = [score(p) for p in range(1, 101)]
print(min(scores))

