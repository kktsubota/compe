n, k = map(int, input().split())
A = list(map(int, input().split()))

count_left = [0 for i in range(n)]
count_right = [0 for i in range(n)]

for i in range(len(A)):
    for j in range(i):
        if A[i] < A[j]:
            count_left[i] += 1
    
    for j in range(i + 1, n):
        if A[i] < A[j]:
            count_right[i] += 1

mod = 10 ** 9 + 7 
# print(count_left)
# print(count_right)
ans = 0
for i in range(n):
    ans += k * count_left[i]
    ans %= mod
    ans += (count_left[i] + count_right[i]) * (k - 1) * k // 2
    ans %= mod
print(ans)

# ans_r = sum(count_right) * k % mod
# ans_l = sum(count_left) * (k - 1) % mod
# print((ans_r + ans_l) % mod)


# # ans = 0
# # for i in range(len(A) - 1):
# #     if A[i] > A[i + 1]:
# #         ans += 1

# # if A[-1] > A[0]:
# #     ans = (ans + 1) * k - 1
# # else:
# #     ans = ans * k
# # print(ans % (10 ** 9 + 7))
