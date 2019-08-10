import numpy as np


N, K = map(int, input().split())
S = input()

# search where 0
s_arr = np.fromiter(map(int, S), int)
arr = np.array([1] + s_arr.tolist() + [1])
diff = np.diff(arr)
heads = np.where(diff == -1)[0]
tails = np.where(diff == 1)[0]

assert heads.size == tails.size

# large -> small
indices = np.argsort(tails - heads)[::-1]
k = min(K, len(indices))
for i in range(k):
    idx = indices[i]
    head, tail = heads[idx], tails[idx]
    s_arr[head:tail] = 1

# search where 1
arr = np.array([0] + s_arr.tolist() + [0])
diff = np.diff(arr)
heads = np.where(diff == 1)[0]
tails = np.where(diff == -1)[0]

assert heads.size == tails.size

print((tails - heads).max())
# heads = list()
# tails = list()
# is_cntinue = False
# for i in range(len(S)):
#     if not is_continue and S[i] == '0':
#         heads.append(i)
#         is_continue = True
    
#     if is_continue and S[i] == '1':
#         tails.append(i)
#         is_continue = False
