import string

dic = {i: c for i, c in enumerate(string.ascii_uppercase)}
dic_inv = {c: i for i, c in enumerate(string.ascii_uppercase)}
length = len(string.ascii_uppercase)

n = int(input())
s = input()

s_new = [dic[(dic_inv[c] + n) % length] for c in s]
print(''.join(s_new))
