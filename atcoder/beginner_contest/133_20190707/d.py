N = int(input())
As = list(map(int, input().split()))

# assert N % 2 == 1
x_sum = sum(As)
x_n = x_sum - sum(As[0::2][:-1]) * 2
Xs = list()
for i in range(N):
    if i == 0:
        Xs.append(x_n)
    else:
        x = 2 * As[N - i - 1] - Xs[-1]
        Xs.append(x)

Xs = reversed(Xs)
print(' '.join(map(str, Xs)))