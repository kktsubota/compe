N, M = map(int, input().split())
As = [int(input()) for i in range(M)]
As = set(As)
MOD = 1000000007

cache = dict()
def n_steps(n):
    if n not in cache:
        if n in As:
            value = 0
        
        elif n in {0, 1}:
            value = 1

        else:
            value = n_steps(n - 1) + n_steps(n - 2)
            value %= MOD

        cache[n] = value
    return cache[n]

for i in range(N):
    n_steps(i)
print(n_steps(N))