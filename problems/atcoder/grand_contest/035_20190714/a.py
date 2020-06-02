from collections import Counter


n = int(input())
a = list(map(int, input().split()))


def main():
    if all(map(lambda e: e == 0, a)):
        print('Yes')
        return

    if n % 3 != 0:
        print('No')
        return

    count = dict(Counter(a))
    keys = list(count.keys())
    values = list(count.values())
    # a, b, c a^b^c=0
    if len(count) == 3:
        if values[0] == values[1] and values[1] == values[2] and (keys[0] ^ keys[1] ^ keys[2]) == 0:
            print('Yes')
        else:
            print('No')
    # a, a, 0 a^b^c=0
    elif len(count) == 2:
        if 0 not in count:
            print('No')
        elif (2 * count[0]) == max(values):
            print('Yes')
        else:
            print('No')
    # 0, 0, 0 -> L.9
    else:
        print('No')


if __name__ == "__main__":
    main()
    