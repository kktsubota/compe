from functools import lru_cache


MOD = 1000000007

def gcd(a, b):
    if a < b:
        return gcd(b, a)
    r = a % b
    if r == 0:
        return b
    else:
        return gcd(b, r)


def get_divisors(n):
    divs = list()
    for i in range(1, n + 1):
        if i * i >= n:
            break
        if n % i == 0:
            divs.append(i)
            divs.append(n // i)
    
    if (i * i) == n:
        divs.append(i)
    return sorted(divs)[::-1]

divisors_dict = {i: get_divisors(i) for i in range(1, 10 ** 5 + 1)}

def func(n, k):
    if n == 1:
        return (1,) * k
    # 1 - n//2
    half_1 = func(n // 2, k)
    # n//2+1 - n
    half_2 = func(n - n // 2, k)

    ret = [0 for i in range(k)]
    # O(K^2)

    # O (K sqrt(K))
    sum_dict = {g: sum(half_2[g-1::g]) for g in range(1, k + 1)}

    for i, v1 in enumerate(half_1):
        i += 1
        # sqrt(K)
        if True:
            divisors = divisors_dict[i]
            for div in divisors:         
                g = div
                c = sum_dict[g] - sum([sum_dict[_g] for _g in divisors if (_g % g == 0 and _g != g)])
                ret[g - 1] += v1 * (c % MOD)
                ret[g - 1] %= MOD
        # O(K)
        else:
            for j, v2 in enumerate(half_2):
                j += 1

                g = gcd(i, j)
                ret[g - 1] += (v1 * v2 % MOD)
                ret[g - 1] %= MOD

        # if i == 1:
        #     g = 1
        #     ret[g - 1] += v1 * (sum_of_half_2 % MOD) % MOD
        #     ret[g - 1] %= MOD
        # elif i == 2:
        #     g = 2
        #     s = sum(half_2[1::2])
        #     ret[g - 1] += v1 * (s % MOD) % MOD
        #     g = 1
        #     ret[g - 1] += v1 * ((sum_of_half_2 - s) % MOD) % MOD
    
    return tuple(ret)


def main():
    n, k = map(int, input().split())
    # O(K^2 logN)
    ret = func(n, k)
    ans = 0
    for i, v in enumerate(ret):
        i += 1
        ans += (i * v)
        ans %= MOD
    
    return ans


print(main())
