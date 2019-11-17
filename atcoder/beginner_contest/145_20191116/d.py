MOD = 10 ** 9 + 7


def pow_mod(a, n):
    if n == 0:
        return 1
    p = pow_mod(a, n // 2)
    if n % 2 == 0:
        return (p * p) % MOD
    else:
        return (a * p * p) % MOD
        

def main():
    x, y = map(int, input().split())
    if (x + y) % 3 != 0:
        return 0
    
    n = (x + y) // 3
    x -= n
    y -= n
    if x < 0 or y < 0:
        return 0
    else:
        ans = 1
        for i in range(x + 1, x + y + 1):
            ans = (ans * i) % MOD
        for i in range(1, y + 1):
            ans = (ans * pow_mod(i, MOD - 2)) % MOD
        return ans


if __name__ == "__main__":
    print(main())