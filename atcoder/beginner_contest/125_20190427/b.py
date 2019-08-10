N = int(input())
Vs = list(map(int, input().split()))
Cs = list(map(int, input().split()))

diffs = [V - C for V, C in zip(Vs, Cs)]
diffs = sorted(diffs)

ans = 0
for diff in diffs[::-1]:
    if diff >= 0:
        ans += diff

print(ans)