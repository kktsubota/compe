from collections import Counter


n = int(input())
S = list()
for i in range(n):
    S.append(input())

count = Counter(S)
v_max = max(count.values())
keys = list()
for key, value in count.items():
    if value == v_max:
        keys.append(key)

keys = sorted(keys)
for key in keys:
    print(key)
