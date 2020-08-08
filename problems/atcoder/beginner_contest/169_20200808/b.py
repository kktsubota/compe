n = int(input())
a = list(map(int, input().split()))

ans = 1

if 0 in a:
    print(0)

else:
    for e in a:
        ans *= e
        if ans > 10 ** 18:
            ans = -1
            break
    print(ans)