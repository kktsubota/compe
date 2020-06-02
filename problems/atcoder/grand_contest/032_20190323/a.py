N = int(input())
b = list(map(int, input().split()))


def naive():
    # (1), (1,2), ..., (1,...,N)
    import itertools
    candidates = itertools.product(*[range(1, i + 1) for i in range(1, N+1)])
    for candidate in candidates:
        a = list()
        for j in candidate:
            a.insert(j-1, j)

        if a == b:
            return candidate
    
    return -1


def fast():
    candidate = list()
    
    while len(b) != 0:
        for i in range(len(b))[::-1]:
            if b[i] == (i+1):
                value = b.pop(i)
                candidate.append(value)
                break
            
        else:
            return [-1]

    candidate.reverse()
    return candidate
 
# print(naive())
# print(fast())
ans_list = fast()
for ans in ans_list:
    print(ans)
