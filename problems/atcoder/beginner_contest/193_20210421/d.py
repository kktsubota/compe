from collections import defaultdict
import itertools

def to_dict(st):
    d = defaultdict(int)
    for c in st:
        d[int(c)] += 1
    return d

def get_score(d):
    score = 0
    for l in range(1, 10):
        score += l * (10 ** d[l])
    return score


k = int(input())
s = input()[:-1]
t = input()[:-1]

s_dict = to_dict(s)
t_dict = to_dict(t)

ans = [0, 0]
for i, j in itertools.product(range(1, 10), range(1, 10)):
    # calculate #cases
    if i == j:
        num_i = k - s_dict[i] - t_dict[i]
        num_j = num_i - 1
    else:
        num_i = k - s_dict[i] - t_dict[i]
        num_j = k - s_dict[j] - t_dict[j]
    n_cases = num_i * num_j

    # calculate win or lose
    s_dict[i] += 1
    t_dict[j] += 1

    s_win = get_score(s_dict) > get_score(t_dict)

    s_dict[i] -= 1
    t_dict[j] -= 1

    ans[1] += n_cases

    if s_win:
        ans[0] += n_cases

print(ans[0] / ans[1])