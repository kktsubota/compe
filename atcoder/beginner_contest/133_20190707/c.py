l, r = map(int, input().split())
l = l % 2019
r = r % 2019

if l >= r:
    # must be 0 at some point
    print(0)

