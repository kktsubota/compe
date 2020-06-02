a, b = map(int, input().split())

diff = abs(b - a)
ans = 0
while diff != 0:
    # print(diff, ans)
    if diff >= 8:
        diff = abs(diff - 10)
        ans += 1

    elif diff >= 3:
        diff = abs(diff - 5)
        ans += 1
    
    else:
        ans += diff
        diff = 0

print(ans)
