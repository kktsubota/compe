def dist(a, b):
    a_bin = '{:017b}'.format(a)
    b_bin = '{:017b}'.format(b)
    
    dist = 0
    for c_a, c_b in zip(a_bin, b_bin):
        if c_a == c_b:
            dist += 1
    
    return dist


n, a, b = map(int, input().split())
dist(a, b)
