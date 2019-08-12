import string


n = int(input())

Ss = list()
for i in range(n):
    Ss.append(input())

# import random
# n = 100000
# Ss = list()
# for i in range(n):
#     Ss.append(random.sample(string.ascii_lowercase, 10))

count_dict = dict()
for s in Ss:
    count = [0 for i in range(len(string.ascii_lowercase))]
    for j in range(len(s)):
        count[ord(s[j]) - ord('a')] += 1
    count = tuple(count)
    if count in count_dict:
        count_dict[count] += 1
    else:
        count_dict[count] = 1
# print(count_dict)
ans = 0
for value in count_dict.values():
    ans += value * (value - 1) // 2
print(ans)
    
        

