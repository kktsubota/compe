from collections import defaultdict
import bisect


n, k = map(int, input().split())
A = list(map(int, input().split()))

S = [0] * (n + 1)
for i in range(1, n + 1):
    S[i] = S[i - 1] + A[i - 1]

T = [0] * (n + 1)
for i in range(1, n + 1):
    T[i] = (S[i] - i) % k

# print(S)
# print(T)
size = defaultdict(list)
for i in range(0, n + 1):
    size[T[i]].append(i)

# print(size)
ans = 0
for i in range(0, n + 1):
    # [index_i, index_j)
    # T[i][index_i] >= i
    # T[i][index_j] < (i + k) because T[i][index_j + 1] >= (i + k)
    index_i = bisect.bisect_left(size[T[i]], i)
    index_j = bisect.bisect_left(size[T[i]], i + k) - 1
    # print(index_i, index_j)
    ans += (index_j - index_i)

print(ans)
