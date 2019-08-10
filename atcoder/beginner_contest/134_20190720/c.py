n = int(input())
As = list()
for i in range(n):
    a = int(input())
    As.append(a)

max_left = list()
max_right = list()

for i in range(n):
    if i == 0:
        max_left.append(As[i])
        max_right.append(As[-1 - i])
    
    else:
        max_left.append(max(max_left[-1], As[i]))
        max_right.append(max(max_right[-1], As[-1-i]))

max_right.reverse()

for i in range(n):
    if i == 0:
        print(max_right[i + 1])
    elif i == n - 1:
        print(max_left[i - 1])
    else:
        print(max(max_left[i - 1], max_right[i + 1]))
