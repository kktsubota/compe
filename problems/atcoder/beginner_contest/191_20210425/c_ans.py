import numpy as np


h, w = map(int, input().split())

s = list()
for i in range(h):
    s.append(list(input()))
s = np.array(s)
ans = 0
for y in range(h - 1):
    for x in range(w - 1):
        # (y, x): crossing points between marks
        marks = s[y:y+2, x:x+2].flatten().tolist()
        if marks.count("#") in {1, 3}:
            # print(y, x)
            ans += 1

print(ans)