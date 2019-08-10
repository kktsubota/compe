import itertools


s = list(input())

count = 0
for nums in itertools.product(*[range(10)] * s.count('?')):
    i = 0
    n = ''
    for c in s:
        if c == '?':
            n += str(nums[i])
            i += 1
        else:
            n += c
    print(n)
    if int(n) % 13 == 5:
        count += 1
print(count)