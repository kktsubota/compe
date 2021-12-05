
def main():
    s = input()
    if len(s) == 1:
        if s == "x" or s == "o":
            return True
        else:
            return False

    elif len(s) == 2:
        # except oo
        if s == "ox" or s == "xo" or s == "xx":
            return True
        else:
            return False

    else:
        # oxxoxx -> oxx, xxo, xox
        subs1 = s[0::3]
        subs2 = s[1::3]
        subs3 = s[2::3]

        flag1: bool = all(c == subs1[0] for c in subs1)
        flag2: bool = all(c == subs2[0] for c in subs2)
        flag3: bool = all(c == subs3[0] for c in subs3)

        # not pattern
        if not (flag1 and flag2 and flag3):
            return False

        if s[:3] == "oxx" or s[:3] == "xxo" or s[:3] == "xox":
            return True
        else:
            return False


if main():
    print("Yes")
else:
    print("No")
