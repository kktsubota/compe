n = int(input())


def main():
    for x in range(1, n + 1):
        if (x * 108 // 100) == n:
            return x
    else:
        return -1


if __name__ == "__main__":
    v = main()
    if v == -1:
        print(':(')
    else:
        print(v)
        