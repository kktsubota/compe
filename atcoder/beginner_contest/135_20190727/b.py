import itertools
import copy


def is_sorted(arr):
    for i in range(len(arr) - 1):
        if arr[i] > arr[i + 1]:
            return False
    return True


def main():
    n = int(input())
    ps = list(map(int, input().split()))

    if is_sorted(ps):
        print('YES')
        return

    for i, j in itertools.combinations(range(n), 2):
        ps_ = copy.deepcopy(ps)
        ps_[i], ps_[j] = ps_[j], ps_[i]
        if is_sorted(ps_):
            print('YES')
            return
    print('NO')
    return


main()