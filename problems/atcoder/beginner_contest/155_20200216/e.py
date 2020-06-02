import sys
sys.setrecursionlimit(10000000)


n = input()

# a[i]: ans for n[:i]
# a = [0 for i in range(len(n) + 1)]
# a[0] = 0
# a[1] = max(a[0] + int(n[0]), (10 - int(n[0])) + 1)
# a[2] = max(a[1] + int(n[1]), a[0] + (10 - int(n[1])) + 1)

# def inv(n):
#     n_new = list()
#     for i in range(len(n)):
#         if n[i] == '9':
#             n_new.append(0)
#         else:
#             n_new.append(9 - int(n[i]))
#     for i in range(len(n)):
#         if n_new[-i] != 9:
#             n_new[-1] += 1
#             break
#         else:
#             n_new[-1] = 0

#     return ''.join(map(str, n_new))


# def func(n, calc_inv=True):
#     if len(n) == 0:
#         return 0

#     if calc_inv:
#         return min(1 + func(inv(n), calc_inv=False), func(n, calc_inv=False))
    
#     else:            
#         return int(n[0]) + func(n[1:])

# print(func(n))

# a = [0 for i in range(len(n) + 1)]
# for i in range(len(n)):
#     if int(n[i]) < 5:
#         a[i + 1] += int(n[i])
#     elif int(n[i]) > 5:
#         a[i] += 1
#         a[i + 1] -= (10 - int(n[i]))
#     else: # 5
#         if a[i] >= 0:
#             a[i + 1] += 5
#         else:
#             a[i] += 1
#             a[i + 1] - 5

# print(a)
# print(sum(map(abs, a)))


a = [0 for i in range(len(n) + 1)]
for i in range(1, len(n) + 1):
    # print(a)
    m = int(n[-i]) + a[i - 1]
    # print(m)
    if m < 5:
        a[i - 1] = m
    elif m > 5:
        a[i] += 1
        a[i - 1] = - (10 - m)
    else: # 5
        if i != len(n) and int(n[-i-1]) >= 5:
            a[i] += 1
            a[i - 1] = - m
        else:
            a[i - 1] = m

# print(a[::-1])
print(sum(map(abs, a)))

