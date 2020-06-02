def main():
    t1, t2 = map(int, input().split())
    a1, a2 = map(int, input().split())
    b1, b2 = map(int, input().split())
    if a1 < b1:
        a1, b1 = b1, a1
        a2, b2 = b2, a2

    div = (a1 - b1) * t1 + (a2 - b2) * t2
    ans = (b1 - a1) * t1

    if div == 0:
        print('infinity')
        return
    elif div > 0:
        # includes a2 > b2
        print('0')
        return

    else:
        if ans % div == 0:
            print(2 * (ans // div))
            return
        else:
            print(2 * (ans // div) + 1)
            return


if __name__ == "__main__":
    main()
