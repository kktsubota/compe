from collections import deque


x, y, a, b, c = map(int, input().split())
p = list(map(int, input().split()))
q = list(map(int, input().split()))
r = list(map(int, input().split()))

p = sorted(p)
q = sorted(q)
baseline = p[-x:] + q[-y:]

r = deque(sorted(r))
baseline = deque(sorted(baseline))

while len(r) != 0:
    v = r.pop()
    if v > baseline[0]:
        baseline.popleft()
        baseline.append(v)
    else:
        break

print(sum(baseline))
