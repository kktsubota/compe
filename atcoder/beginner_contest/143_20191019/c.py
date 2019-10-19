n = int(input())
s = input()

ans = 0
i = 0
while True:
    c = s[i]
    ans += 1
    while i < n and c == s[i]:
        i += 1
    if i == n:
        break
print(ans)
