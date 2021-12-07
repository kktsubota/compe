import numpy as np


n, w = map(int, input().split())
a_list = np.empty(n, dtype=int)
b_list = np.empty(n, dtype=int)

for i in range(n):
    a_list[i], b_list[i] = map(int, input().split())

# descending order
index = np.argsort(a_list)[::-1]
a_list = a_list[index]
b_list = b_list[index]

ans = 0
for a, b in zip(a_list, b_list):
    if w < b:
        ans += a * w
        break
    else:
        ans += a * b
        w -= b

print(ans)
