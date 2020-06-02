def gcd(a, b):
    if a < b:
        return gcd(b, a)
    r = a % b
    if r == 0:
        return b
    else:
        return gcd(b, r)


a, b = map(int, input().split())
g = gcd(a, b)
print(a // g * b)
