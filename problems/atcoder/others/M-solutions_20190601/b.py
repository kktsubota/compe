s = input()

if 15 - len(s) + s.count('o') >= 8:
    print('YES')
else:
    print('NO')