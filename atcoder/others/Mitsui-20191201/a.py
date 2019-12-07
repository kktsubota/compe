m1, d1 = map(int, input().split())
m2, d2 = map(int, input().split())


def main():
    if m1 == 12:
        if m2 == 1 and d2 == 1:
            return True
        else:
            return False
    else:
        if (m1 + 1) == m2 and d2 == 1:
            return True
        else:
            return False


if __name__ == "__main__":
    if main():
        print('1')
    else:
        print('0')