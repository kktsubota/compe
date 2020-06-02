from functools import lru_cache


N = int(input())
As = list()
for i in range(N):
    As.append(int(input()))

MOD = 998244353
S = sum(As)

base = 3 ** N % MOD

# R >= S/2, N
@lru_cache(maxsize=None)
def larger_than_T(T, k):
    """equal to or larger than T in As[:k]
    """
    if T <= 0:
        return 3 ** k
    # T > 0
    if k == 0:
        return 0
    # assign As[k-1] to G or B 
    return 2 * larger_than_T(T, k - 1) + larger_than_T(T - As[k-1], k - 1)

# R = G = S/2, N
@lru_cache(maxsize=None)
def equal_to_Ts(T1, T2, k):
    """R and G are equal to T1 and T2 respectively in As[:k].
    """
    if T1 < 0 or T2 < 0:
        return 0
 
    if k == 0:
        if T1 == 0 and T2 == 0:
            return 1
        else:
            return 0
    
    return equal_to_Ts(T1, T2, k - 1) + equal_to_Ts(T1 - As[k-1], T2, k - 1) + equal_to_Ts(T1, T2 - As[k-1], k - 1)

single = larger_than_T(S/2, N) % MOD
if S % 2 == 0:
    double = equal_to_Ts(S//2, S//2, N) % MOD
else:
    double = 0

# print(base, single, double)
ans = base - single * 3 + double * 3
print(ans % MOD)
