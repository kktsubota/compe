n = int(input())

if n % 2 == 1:
    print(0)

else:
    m = n // 2
    ans = 0
    div = 5
    while (m // div) > 0:
        ans += m // div
        div *= 5
    print(ans)
