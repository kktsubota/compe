s = input()


se = set(list(s))
if len(se) == 2:
    se = list(se)
    if s.count(se[0]) == 2 and s.count(se[1]) == 2:
        print('Yes')

    else:
        print('No')

else:
    print('No')