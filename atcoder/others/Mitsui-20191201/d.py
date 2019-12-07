import itertools
from collections import Counter


n = int(input())
s = input()

numbers = set()
# init
for i in range(1, n - 1):
    if i == 1:
        c = s[i]
        head = dict(Counter(s[i - 1]))
        tail = dict(Counter(s[i + 1:]))

        for h, p in itertools.product(head.keys(), tail.keys()):
            numbers.add((h, c, p))
        if c in head:
            head[c] += 1
        else:
            head[c] = 1
        tail[s[i + 1]] -= 1
        if tail[s[i + 1]] == 0:
            tail.pop(s[i + 1])

    else:
        c = s[i]
        for h, p in itertools.product(head.keys(), tail.keys()):
            numbers.add((h, c, p))

        if i == n - 1:
            break

        if c in head:
            head[c] += 1
        else:
            head[c] = 1
        tail[s[i + 1]] -= 1
        if tail[s[i + 1]] == 0:
            tail.pop(s[i + 1])

print(len(numbers))
