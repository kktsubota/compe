# import numpy as np
from collections import defaultdict
from collections import deque

N = int(input())
ss = list()
for i in range(N):
    ss.append(input())

types = list()
indices_dict = defaultdict(deque)
for i, s in enumerate(ss):
    if s[-1] == 'A':
        if s[0] != 'B':
            type_ = 0
        else:
            type_ = 1

    elif s[0] == 'B':
        type_ = 2
    else:
        type_ = 3
    types.append(type_)
    indices_dict[type_].append(i)

# print(indices_dict)
indices = list()
type_prev = 3
while True:
    # print(indices)
    # does not end with 'A'
    if type_prev in {2, 3}:
        if len(indices_dict[0]) != 0:
            idx = indices_dict[0].pop()
            indices.append(idx)
            type_prev = 0
        elif len(indices_dict[1]) != 0:
            idx = indices_dict[1].pop()
            indices.append(idx)
            type_prev = 1
        elif len(indices_dict[3]) != 0:
            idx = indices_dict[3].pop()
            indices.append(idx)
            type_prev = 3
        elif len(indices_dict[2]) != 0:
            idx = indices_dict[2].pop()
            indices.append(idx)
            type_prev = 2
        else:
            break

    # end with 'A'
    else:
        if len(indices_dict[1]) != 0:
            idx = indices_dict[1].pop()
            indices.append(idx)
            type_prev = 1
        elif len(indices_dict[2]) != 0:
            idx = indices_dict[2].pop()
            indices.append(idx)
            type_prev = 2
        elif len(indices_dict[3]) != 0:
            idx = indices_dict[3].pop()
            indices.append(idx)
            type_prev = 3
        elif len(indices_dict[0]) != 0:
            idx = indices_dict[0].pop()
            indices.append(idx)
            type_prev = 0
        else:
            break

st = ''
for idx in indices:
    st += ss[idx]

ans = 0
for i in range(len(st) - 1):
    if st[i] == 'A':
        if st[i + 1] == 'B':
            ans += 1
print(ans)
# heads = list()
# tails = list()
# for i, s in enumerate(ss):
#     if s[0] == 'B':
#         tails.append(i)

#     if s[-1] == 'A':
#         heads.append(i)

# for tail in tails:
    
