def main():
    h, w, x, y = map(int, input().split())
    x -= 1
    y -= 1

    mass = [input() for i in range(h)]

    ans = 0
    j = y
    for i in range(x + 1, h):
        if mass[i][j] != "#":
            ans += 1
        else:
            break

    for i in range(x - 1, -1, -1):
        if mass[i][j] != "#":
            ans += 1
        else:
            break

    i = x
    for j in range(y + 1, w):
        if mass[i][j] != "#":
            ans += 1
        else:
            break

    for j in range(y - 1, -1, -1):
        if mass[i][j] != "#":
            ans += 1
        else:
            break

    # (x, y)
    ans += 1
    return ans


print(main())