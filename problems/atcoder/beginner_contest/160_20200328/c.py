k, n = map(int, input().split())
A = list(map(int, input().split()))
A.append(A[0] + k)

diff_max = 0
for a, b in zip(A[:-1], A[1:]):
    diff_max = max(diff_max, b - a)

print(k - diff_max)
