import bisect
from collections import defaultdict
from typing import Dict, List


def prime_factorization(n: int) -> Dict[int, int]:
    factorized = defaultdict(int)
    if n == 1:
        return factorized

    if n in {2, 3}:
        factorized[n] += 1
        return factorized

    i: int = 2
    while i * i <= n:
        if n % i == 0:
            factorized[i] += 1
            n = n // i
        else:
            i += 1
    if n != 1:
        factorized[n] += 1
    return factorized


def main():
    n: int = int(input())
    factorized: Dict[int, int] = prime_factorization(n)
    # print(factorized)
    # largest k that satisfies 0.5 * k * (k * 1) <= count
    # 1 + 2 + ... + k
    # 1 + 2 + ... + k + alpha -> 1 + 2 + ... + (k + alpha)
    # count -> k
    # 1 -> 1
    # 2 -> 1
    # 3 -> 2
    ans: int = 0
    thresholds: List[int] = [k * (k + 1) // 2 for k in range(1, 14 * 10 ** 5)]
    for v in factorized.values():
        thresh: int = bisect.bisect_right(thresholds, v)
        ans += thresh
        # print(thresh)
    print(ans)


if __name__ == "__main__":
    main()
    