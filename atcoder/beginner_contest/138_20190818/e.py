import bisect
from collections import defaultdict


def in_sort(a, x):
    i = bisect.bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    raise ValueError


def main():
    s = input()
    t = input()

    c_idx = defaultdict(list)

    for i, c in enumerate(s):
        c_idx[c].append(i)

    idx = -1
    ans = 0
    for c in t:
        if len(c_idx[c]) == 0:
            return -1

        idx_in_c = bisect.bisect_right(c_idx[c], idx)
        # next s
        if idx_in_c == len(c_idx[c]):
            idx -= len(s)
            ans += len(s)
            idx_in_c = bisect.bisect_right(c_idx[c], idx)
        
        idx = c_idx[c][idx_in_c]

    return ans + idx + 1


if __name__ == "__main__":
    print(main())
