n, k = map(int, input().split())
Hs = list(map(int, input().split()))
count = 0
for h in Hs:
    if h >= k:
        count += 1
print(count)
