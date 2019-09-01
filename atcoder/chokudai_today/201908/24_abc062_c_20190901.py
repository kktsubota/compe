h, w = map(int, input().split())

ans_list = list()
# S_list = list()
# h1
for h1 in {h // 3, h // 3 + 1}:
    h_rest = h - h1
    if h1 <= 0 or h_rest <= 0:
        continue
    # h2
    h2 = h_rest >> 1
    if h2 != 0:
        S = [h1 * w, h2 * w, (h_rest - h2) * w]
        ans_list.append(max(S) - min(S))
        # S_list.append(S)

    # w2
    w2 = w >> 1
    if w2 != 0:
        S = [h1 * w, h_rest * w2, h_rest * (w - w2)]
        # S_list.append(S)
        ans_list.append(max(S) - min(S))


for w1 in {w // 3, w // 3 + 1}:
    w_rest = w - w1
    if w1 <= 0 or w_rest <= 0:
        continue
    # w2
    w2 = w_rest >> 1
    if w2 != 0:
        S = [h * w1, h * w2, h * (w_rest - w2)]
        ans_list.append(max(S) - min(S))
        # S_list.append(S)
    # h2
    h2 = h >> 1
    if h2 != 0:
        S = [h * w1, h2 * w_rest, (h - h2) * w_rest]
        ans_list.append(max(S) - min(S))
        # S_list.append(S)

# print(ans_list)
# print(S_list)
print(min(ans_list))
