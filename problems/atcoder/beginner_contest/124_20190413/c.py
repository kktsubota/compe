S = input()
S_num = list(map(int, S))

n_white_even = sum(S_num[0::2])
n_black_even = len(S_num[0::2]) - n_white_even
n_white_odd = sum(S_num[1::2])
n_black_odd = len(S_num[1::2]) - n_white_odd

# even: white, odd: black
cand_1 = n_black_even + n_white_odd
# even: black, odd: white
cand_2 = n_white_even + n_black_odd

print(min(cand_1, cand_2))
