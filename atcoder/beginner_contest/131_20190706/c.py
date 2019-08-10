A, B, C, D = map(int, input().split())


def gcd(a, b):
    if b > a:
        return gcd(b, a)
    
    r = a % b
    if r == 0:
        return b
    else:
        return gcd(b, r)


def count(n, c, d):
    n_c = n // c
    n_d = n // d
    g = gcd(c, d)
    n_cd = n // (c * d // g)
    return n - n_c - n_d + n_cd


print(count(B, C, D) - count(A - 1, C, D))