N, X = map(int, input().split())
S = list(map(int, input().split()))
S = set(S)

cache = dict()
def func(x, s):
    if (x, s) not in cache:
        values = list()
        for i in range(len(s)):
            s = s.copy().remove(s[i])
            value = func(x % s[i], s)
            values.append(value)
        cache[(x, s)] = sum(values)

    return cache[(x, s)]

func(X, S)