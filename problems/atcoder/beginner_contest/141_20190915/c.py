n, k, q = map(int, input().split())
score = {i: 0 for i in range(n)}
for i in range(q):
    a = int(input()) - 1
    score[a] += 1

for i in range(n):
    if k - q + score[i] > 0:
        print('Yes')
    else:
        print('No')
