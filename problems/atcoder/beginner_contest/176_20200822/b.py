n = input()

s = sum(map(int, list(n)))
if s % 9 == 0:
    print('Yes')
else:
    print('No')
    