# n = int(input())
# Hs = list(map(int, input().split()))

# ans = 0
# point = list()
# point.append(-1)
# for i, (h1, h2) in enumerate(zip(Hs[:-1], Hs[1:])):
#     if h1 < h2:
#         point.append(i)

# point.append(n - 1)
# ans = 0
# for p1, p2 in zip(point[:-1], point[1:]):
#     ans = max(ans, p2 - (p1+1))
# print(ans)

#         ans = max(ans, count)

n = int(input())
Hs = list(map(int, input().split()))

ans = 0
count = 0
for h1, h2 in zip(Hs[:-1], Hs[1:]):
    if h1 >= h2:
        count += 1
    
    else:
        ans = max(ans, count)
        count = 0

ans = max(ans, count)
print(ans)
