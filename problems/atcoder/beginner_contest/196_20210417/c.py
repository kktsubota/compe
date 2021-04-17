n = int(input())

# 11 - 99: 9
# 1010 - 9999: 90
# 100100 - 999999: 900
# ...
size = len(str(n))
if size % 2 != 0:
    ans = 10 ** (size // 2) - 1

else:
    ans = 10 ** (size // 2 - 1) - 1
    a = int(str(n)[0:size // 2])
    b = int(str(n)[size // 2:])
    if a <= b:
        # ... <a><a>
        # when size = 2, 11 ... aa
        ans += a - (10 ** (size // 2 - 1)) + 1
    else:
        # ... <a-1><a-1>
        ans += a - 1 - (10 ** (size // 2 - 1)) + 1

print(ans)
