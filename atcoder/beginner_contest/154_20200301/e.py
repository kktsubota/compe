import sys
sys.setrecursionlimit(100000)

# m digits, k, less than flag
n = input()
K = int(input())


def func(i, k, free=False):
    # rest digits
    m = len(n) - i

    # cannot fill m digits with 0 * k
    if k > m:
        return 0

    if m == 0:
        return 1
    # fill all digits with 0
    if k == 0:
        return 1

    if free:
        a = 9 ** k
        # print(a)
        for j in range(k):
            a *= (m - j)
        for j in range(k):
            a = a // (j + 1)
        # print(a)
        return a

    else:
        if n[i] != '0':
            # fill with 0
            a = func(i + 1, k, free=True)

            # 1, 2, ..., n[i] - 1
            b = (int(n[i]) - 1) * func(i + 1, k - 1, free=True)

            # n[i]
            c = func(i + 1, k - 1, free=False) 
            # print(i, a, b, c, k, m)
            return a + b + c
        else:
            # fill with 0
            c = func(i + 1, k, free=False)
            return c


print(func(0, K, free=False))
