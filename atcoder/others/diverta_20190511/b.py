R, G, B, N = map(int, input().split())

# max num
n_r = N // R
n_g = N // G
n_b = N // B
ans = 0
for i in range(n_r + 1):
    for j in range(n_g + 1):
        num = N - R * i - G * j
        if num >= 0 and num % B == 0:
            # print(i, j, num // B)
            ans += 1
print(ans)