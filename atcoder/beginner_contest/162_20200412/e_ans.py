MOD = 10 ** 9 + 7

n, k = map(int, input().split())

def pow_mod(a, n):
    if n == 1:
        return a
    half = pow_mod(a, n // 2)
    if n % 2 == 1:
        ret = half * a % MOD
        ret = ret * half % MOD
    else:
        ret = half * half % MOD
    return ret

ans_dict = dict()
for g in range(k, 0, -1):
    ans_dict[g] = pow_mod(k // g, n)
    for i in range(2, k + 1):
        if g * i <= k:
            ans_dict[g] -= ans_dict[g * i]
            if ans_dict[g] < 0:
                ans_dict[g] += MOD
            elif ans_dict[g] > g:
                ans_dict[g] -= MOD
        else:
            break

ans = 0
for g, v in ans_dict.items():
    ans += g * v
    ans %= MOD

print(ans)
