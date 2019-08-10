n = int(input())


def naive():
    import itertools

    comb = list(itertools.combinations(range(n), 2))
    candidates = n * (n - 1) // 2 # len(comb)
