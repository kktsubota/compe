import bisect

import numpy as np


def main():
    s = input()
    k = int(input())
    # s = "XX.....X...XXX.."
    # k = 3

    # the count of X...X..XX -> (1, 3, 2, 2, 2)
    # if no X in the beginning and ending of string, (0, ..., 0)

    cnt_list = list()

    cnt = 0
    for i, c in enumerate(s):
        if i == 0:
            if c == ".":
                cnt_list.append(cnt)

        elif c != s[i - 1]:
            cnt_list.append(cnt)
            cnt = 0
        
        cnt += 1

    else:
        cnt_list.append(cnt)
        cnt = 0
        if s[-1] == ".":
            cnt_list.append(cnt)

    # print(cnt_list)
    # the count of X is cnt_list[0::2], the count of . is list[1::2]
    x_cumsum = np.cumsum(cnt_list[0::2])
    d_cumsum = np.cumsum(cnt_list[1::2])
    # print(x_cumsum)
    # print(d_cumsum)

    if len(d_cumsum) == 0:
        return x_cumsum[-1]

    elif d_cumsum[-1] <= k:
        return len(s)

    ans = 0
    for j in range(d_cumsum[-1] - k + 1):
        # fill [j, j + k)-th "."
        # 1, 3, 6 -- X.X..X...X
        # use X of [index_beg, index_end] regions

        # bisect_right causes a bug when ending with "."
        index_end = bisect.bisect_left(d_cumsum, k + j)
        if d_cumsum[index_end] == (k + j):
            index_end += 1

        index_beg = bisect.bisect_left(d_cumsum, j)
        if j == 0:
            x_cnt = x_cumsum[index_end]
        else:
            x_cnt = x_cumsum[index_end] - x_cumsum[index_beg]

        # print(j, index_beg, index_end, x_cnt + k)
        ans = max(ans, x_cnt + k)
        # d_cnt = d_cumsum[index_end] - d_cumsum[index_beg]
        # ans = max(ans, x_cnt + d_cnt + k - d_cnt)

    return ans


print(main())