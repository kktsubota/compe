n, k, c = map(int, input().split())
s = input()

left = [0 for i in range(n + 1)]
right = [0 for i in range(n + 1)]

left[0] = 0
i = 1
cnt = 0
while i <= n:
    if s[i - 1] == 'o':
        cnt += 1
        for j in range(c + 1):
            left[i] = cnt
            i += 1
            if i == (n + 1):
                break
    else:
        left[i] = cnt
        i += 1

right[n] = 0
i = n - 1
cnt = 0
while i >= 0:
    if s[i] == 'o':
        cnt += 1
        right[i] = cnt
        for j in range(c + 1):
            right[i] = cnt
            i -= 1
            if i == -1:
                break
    else:
        right[i] = cnt
        i -= 1

# print(left)
# print(right)
for i in range(n):
    # skip i th element
    if left[i] + right[i + 1] >= k:
        continue
    print(i + 1)