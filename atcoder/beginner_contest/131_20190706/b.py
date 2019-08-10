N, L = map(int, input().split())

apples = [L + i for i in range(N)]
if min(apples) > 0:
    diff = min(apples)
elif max(apples) < 0:
    diff = max(apples)
else:
    diff = 0
print(sum(apples) - diff)