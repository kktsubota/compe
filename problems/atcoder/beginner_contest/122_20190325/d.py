N = int(input())


def match(s):
    if 'AGC' in s:
        return False
    if 'ACG' in s:
        return False
    if 'GAC' in s:
        return False
    for c in 'ATGC':
        if 'A' + c + 'GC' in s:
            return False
        if 'AG' + c + 'C' in s:
            return False
    return True


cache = dict()
def func(n):
    if n in cache:
        return cache[n]

    if n <= 100:
        import itertools
        candidates = itertools.product(*([{'A', 'T', 'G', 'C'}] * n))
        count = 0
        for candidate in candidates:
            if match(''.join(candidate)):
                count += 1
        
        cache[n] = count

    else:
        cache[n] = 4 * func(n-1) - func(n-3) - 8 * func(n-4)
    
    cache[n] = cache[n] % (10 ** 9 + 7)
    return cache[n]

print(func(N))

