N = int(input())
s = input()

red = 0
for i in range(N):
    if s[i] == 'R':
        red += 1
if red > (N - red):
    print('Yes')

else:
    print('No')

