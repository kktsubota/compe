# DO NOT PASS
import bisect


def argsort(seq: list) -> list:
    # https://stackoverflow.com/questions/3407414/python-sort-without-lambda-expressions
    return [i for (v, i) in sorted((v, i) for (i, v) in enumerate(seq))]


n, d = map(int, input().split())

wall_lefts = list()
wall_rights = list()
for i in range(n):
    l, r = map(int, input().split())
    wall_lefts.append(l)
    wall_rights.append(r)

index_r: list = argsort(wall_rights)
wall_rights = [wall_rights[i] for i in index_r]
index_l = argsort(wall_lefts)
wall_lefts = [wall_lefts[i] for i in index_l]
exist_flag = [True for i in range(n)]

ans: int = 0
i_ll: int = 0
# i_r: index for right
for i_r in range(n):
    # 1. break the most left wall
    idx_break_left = index_r[i_r]
    # already broken
    if not exist_flag[idx_break_left]:
        continue
    exist_flag[idx_break_left] = False

    # punch [wall, wall + d)
    # 2. break other walls whose left is smaller than wall + d
    # if the left is smaller than wall, it should be [smaller than wall. larger than wall)
    wall = wall_rights[i_r]

    # i_ll, i_lr: index for left
    # i_ll = bisect.bisect_left(wall_lefts, wall)
    i_lr = i_ll + bisect.bisect_left(wall_lefts[i_ll:], wall + d)
    index_break = index_l[i_ll:i_lr]
    for idx in index_break:
        exist_flag[idx] = False

    i_ll = i_lr
    # update wall_lefts (costly)
    # del wall_lefts[:i_lr]
    # del index_l[:i_lr]

    ans += 1

print(ans)
