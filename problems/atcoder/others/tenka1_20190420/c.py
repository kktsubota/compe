import copy


N = int(input())
S = input()
S = list(S)


def get_answer(S, indices_b, indices_w):
    # most left
    if len(indices_b) == 0 or len(indices_w) == 0:
        return 0

    # turn most right white -> black
    if indices_w[-1] < indices_b[0]:
        return 0

    S_w = S.copy()
    S_w[indices_w[-1]] = '#'
    ans_w = get_answer(S_w, indices_b, indices_w[:-1]) + 1

    # turn most left black -> white
    S_b = S.copy()
    S_b[indices_b[0]] = '.'
    ans_b = get_answer(S_b, indices_b[1:], indices_w) + 1
    return min(ans_b, ans_w)

indices_white = list()
indices_black = list()

for i, c in enumerate(S):
    if c == '#':
        indices_black.append(i)
    elif c == '.':
        indices_white.append(i)

print(get_answer(S, indices_black, indices_white))