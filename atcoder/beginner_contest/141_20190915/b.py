s = input()


def main():
    for i, c in enumerate(s):
        if i % 2 == 0:
            if c in {'R', 'U', 'D'}:
                pass
            else:
                return False
        if i % 2 == 1:
            if c in {'L', 'U', 'D'}:
                pass
            else:
                return False
    return True


if main():
    print('Yes')
else:
    print('No')
