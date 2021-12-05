n, a, b = map(int, input().split())
p, q, r, s = map(int, input().split())

output = [["." for _ in range(s - r + 1)] for _ in range(q - p + 1)]
# for row in output:
#     print("".join(row))
# print()
k_min = max(1 - a, 1 - b)
k_max = min(n - a, n - b)
for i in range(q - p + 1):
    for j in range(s - r + 1):
        # for k in range(k_min, k_max + 1):
        #     if (p + i) == (a + k) and (r + j) == (b + k):
        #         output[i][j] = "#"

        k_x = p + i - a
        k_y = r + j - b
        if k_x == k_y and k_min <= k_x <= k_max:
            output[i][j] = "#"
            
k_min = max(1 - a, b - n)
k_max = min(n - a, b - 1)
for i in range(q - p + 1):
    for j in range(s - r + 1):
        # for k in range(k_min, k_max + 1):
        #     if (p + i) == (a + k) and (r + j) == (b - k):
        #         output[i][j] = "#"
        k_x = p + i - a
        k_y = - (r + j - b)
        if k_x == k_y and k_min <= k_x <= k_max:
            output[i][j] = "#"

for row in output:
    print("".join(row))
