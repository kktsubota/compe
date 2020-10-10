MOD = 1000000007

t = int(input())

inputs = list()
for i in range(t):
    n, a, b = map(int, input().split())
    inputs.append((n, a, b))

for n, a, b in inputs:
    cnt = 0
    a, b = min(a, b), max(a, b)

    if n - a - b < 0:
        ans = 0
    else:
        # 1. corner
        temp = (n - a - b + 1) * (a - 1) % MOD
        temp = (temp + (a - 1) * a // 2) % MOD
        temp = (temp * temp) % MOD
        cnt = 4 * temp % MOD
        # print(4 * temp)

        # 2. edge
        temp = (n - a - b + 1) * (a - 1) % MOD
        temp = (temp + (a - 1) * a // 2) % MOD
        temp = temp * (n - b + 1) % MOD
        temp = temp * (b - a + 1) % MOD
        cnt += (4 * temp % MOD)
        cnt %= MOD
        # print(4 * temp % MOD)

        # 3. inner
        temp = (b - a + 1) ** 2
        temp %= MOD
        temp = temp * (n - b + 1) % MOD
        temp = temp * (n - b + 1) % MOD
        # print(temp)
        cnt += temp
        cnt %= MOD
        assert cnt >= 0

        cnt_a = (n - a + 1) * (n - a + 1) % MOD
        cnt_b = (n - b + 1) * (n - b + 1) % MOD
        ans = cnt_a * cnt_b % MOD - cnt
        if ans < 0:
            ans += MOD

    assert ans >= 0
    print(ans)
