import bisect
import heapq
import numpy as np

n = int(input())
a = np.fromiter(map(int, input().split()), dtype=int)
rank = np.argsort(a)

# k = 0
ans = 0
b = list()
for i in range(n):
    # b = [1, 2, 3, 5], a[i] = 4
    # -> idx = 3
    n_small = bisect.bisect_left(b, a[i])    
    print("#small", n_small, i - n_small, b, a[i])
    heapq.heappush(b, a[i])
    ans += (i - n_small)

# k >= 1
for k in range(n):
    if k == 0:
        pass
    else:
        r = rank[-k]
        ans = ans + r - (n - r - 1)
    print(ans)
