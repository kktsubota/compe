import numpy as np


def main():
    n, k = map(int, input().split())
    p = np.empty((n,), dtype=int)
    for i in range(n):
        p[i] = sum(map(int, input().split()))

    if k == n:
        return [True for i in range(n)]

    # top k
    answers = list()
    index = np.argsort(p)[-k:]
    top_k = index[0]
    top_ks = set(index.tolist())
    for i in range(n):
        # already top-k
        if i in top_ks:
            answers.append(True)
            continue
        
        if p[top_k] - p[i] <= 300:
            answers.append(True)
        else:
            answers.append(False)
    return answers


answers = main()
for ans in answers:
    if ans:
        print("Yes")
    else:
        print("No")

