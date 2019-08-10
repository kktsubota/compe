import sys
sys.setrecursionlimit(1000000)


N, A, B, C = map(int, input().split())


MOD = 10 ** 9 + 7
def pow(a, n):
    if n == 0:
        return 1
    else:
        return a * (pow(a, n - 1) % MOD)

a_n = pow(A, N)
b_n = pow(B, N)
n_100 = pow(100, N)

child = (100 - A) * a_n * ((n_100 + MOD - b_n) % MOD) * 10000
child += (100 - B) * b_n * ((n_100 + MOD - a_n) % MOD) * 10000
parent = (100 - A) * (100 - B) * (100 - C) * n_100 ** 2

print(child % MOD, parent % MOD)
