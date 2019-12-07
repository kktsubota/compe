x = int(input())

y = x % 100
if y % 5 == 0:
    num = y // 5
else:
    num = y // 5 + 1

if x >= (100 * num):
    print('1')
else:
    print('0')
