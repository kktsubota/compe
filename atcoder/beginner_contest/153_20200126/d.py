h = int(input())

def count(x):
    if x == 1:
        return 1
    else:
        return 2 * count(x // 2) + 1

print(count(h))