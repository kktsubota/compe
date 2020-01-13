n, k = map(int, input().split())
A = list(map(int, input().split()))
A = sorted(A)

MOD = 10 ** 9 + 7


def pow(a, n):
    if n == 0:
        return 1
    else:
        temp = pow(a, n // 2)
        if n % 2 == 0:
            return temp * temp % MOD
        else:
            return temp * temp * a % MOD
        
        
ans = 0
combinations = list()
for j, i in enumerate(range(k - 1, n)):
    if i == (k - 1):
        combinations.append(1)
    else:
        combinations.append(combinations[-1] * i * pow(i - k + 1, MOD - 2))
    combinations[-1] = combinations[-1] % MOD
    # print(i, 'C', k - 1, '=', combinations[-1])

# print(combinations)
# print(A)
combinations = combinations[::-1]
for j, i in enumerate(range(k - 1, n)):
    ans += (A[-j - 1] * combinations[j] % MOD)

for j, i in enumerate(range(k - 1, n)):
    ans -= (A[j] * combinations[j] % MOD)
    if ans < 0:
        ans = ans + (- ans // MOD + 1) * MOD

ans %= MOD
print(ans)
