import sys
sys.setrecursionlimit(200000)


N = int(input())
S = input()
S = list(S)


indices_black = list()
for i, c in enumerate(S):
    if c == '#':
        indices_black.append(i)

count_white = dict()
count = 0
for i, c in enumerate(S[::-1]):
    if c == '.':
        count += 1
    count_white[N - i - 1] = count


def get_answer(S):
    # most left
    if len(indices_black) == 0:
        return 0

    idx = indices_black.pop(0)
    if count_white[idx] == 0:
        return 0
    # count white: turn all white -> black
    ans_w = count_white[idx]

    # turn most left black -> white
    S[idx] = '.'
    ans_b = get_answer(S) + 1
    return min(ans_w, ans_b)


print(get_answer(S))