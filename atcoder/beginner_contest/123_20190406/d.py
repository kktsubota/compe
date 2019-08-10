import numpy as np


x, y, z, k = map(int, input().split())
As = list(map(int, input().split()))
Bs = list(map(int, input().split()))
Cs = list(map(int, input().split()))

As = sorted(As, reverse=True)
Bs = sorted(Bs, reverse=True)
Cs = sorted(Cs, reverse=True)

idx_1, idx_2, idx_3 = 0, 0, 0
INF = 10 ** 11
answers = list()

candidates = [(idx_1, idx_2, idx_3)]
end_cands = set()
values = [As[idx_1] + Bs[idx_2] + Cs[idx_3]]
for i in range(k):
    while True:
        ans_idx = np.argmax(values)
        cand = candidates.pop(ans_idx)
        ans = values.pop(ans_idx)
        if cand not in end_cands:
            break
    idx_1, idx_2, idx_3 = cand
    answers.append(ans)
    end_cands.add(cand)
    # print(cand, ans)

    if idx_1 + 1 != x:
        candidates.append((idx_1 + 1, idx_2, idx_3))
        values.append(As[idx_1 + 1] + Bs[idx_2] + Cs[idx_3])
    if idx_2 + 1 != y:
        candidates.append((idx_1, idx_2 + 1, idx_3))
        values.append(As[idx_1] + Bs[idx_2 + 1] + Cs[idx_3])
    if idx_3 + 1 != z:
        candidates.append((idx_1, idx_2, idx_3 + 1))
        values.append(As[idx_1] + Bs[idx_2] + Cs[idx_3 + 1])

for ans in answers:
    print(ans)
