N = int(input())
Ws = list(map(int, input().split()))

diff = sum(Ws)
for i in range(1, N+1):
    diff = min(diff, abs(sum(Ws[:i]) - sum(Ws[i:])))

print(diff)