import math


def sqrt(x: int):
    i = 0
    while True:
        s = i * i
        if s == x:
            return i
        i += 1
        if s > x:
            break
    return math.sqrt(x)
    
r, x, y = map(int, input().split())

dist_l2 = x ** 2 + y ** 2

if dist_l2 == 0:
    print(0)
    
# require two steps
elif dist_l2 < r ** 2:
    print(2)

elif dist_l2 % (r ** 2) == 0:
    c = sqrt(dist_l2 // r // r)
    if isinstance(c, int):
        print(c)
    else:
        print(int(c) + 1)
    
else:
    print(int(math.sqrt(dist_l2) / r) + 1)