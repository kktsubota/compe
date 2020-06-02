n, k = map(int, input().split())
As = list(map(int, input().split()))

value = 0
head = 0
indices = dict()
for i in range(n):
    value += As[i]
    while value >= k:
        indices[head] = i
        value -= As[head]
        head += 1

ans = 0
for head, tail in indices.items():
    # count = 2 ** (n - 1 - tail)
    count = n - tail
    # print('({}, {}): {}'.format(head, tail, count))
    ans += count

print(ans)
