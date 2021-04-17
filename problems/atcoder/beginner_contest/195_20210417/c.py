# 1 - 9: 0 * 9
# 10 - 99: 0 * 90
# 100 - 999: 0 * 900
# 1000 - 9999: 1 * 9000

n = input()

if len(n) <= 3:
    print(0)

else:
    ans = 0
    for i in range(1, len(n) + 1):
        camma = (i - 1) // 3
        if i != len(n):
            num = 9 * 10 ** (i - 1)
        else:
            num = (int(n[0]) - 1) * 10 ** (i - 1)
            num += int(n[1:]) + 1
        ans += camma * num

    print(ans)
