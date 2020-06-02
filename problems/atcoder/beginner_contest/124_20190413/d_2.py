import numpy as np


N, K = map(int, input().split())
S = input()
s_arr = np.fromiter(map(int, S), int)

# search where 1
arr = np.array([0] + s_arr.tolist() + [0])
diff = np.diff(arr)
heads = np.where(diff == 1)[0]
tails = np.where(diff == -1)[0]
assert heads.size == tails.size

if s_arr[0] == 0:
    heads = np.array([0] + heads.tolist())
    tails = np.array([0] + tails.tolist())

if s_arr[-1] == 0:
    heads = np.array(heads.tolist() + [len(s_arr)])
    tails = np.array(tails.tolist() + [len(s_arr)])

ans = 0
for i, head in enumerate(heads):
    idx = min(i + K, len(tails) - 1)
    tail = tails[idx]
    ans = max(ans, tail - head)

print(ans)
