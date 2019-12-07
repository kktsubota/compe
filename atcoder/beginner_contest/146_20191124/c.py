a, b, x = map(int, input().split())

def main():
    n = 10 ** 9
    if (a * n + b * 10) <= x:
        return n
    
    # n < 10 ** 9
    # m = d(N)
    n = 0
    for m in range(1, 10):
        n_cand = (x - m * b) // a
        if 10 ** (m - 1) <= n_cand < 10 ** m:
            n = max(n, n_cand)
        elif n_cand >= 10 ** m:
            n = max(n, 10 ** m - 1)
        else:
            continue
    
    return n


if __name__ == "__main__":
    print(main())
