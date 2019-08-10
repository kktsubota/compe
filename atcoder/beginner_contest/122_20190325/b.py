def is_acgt(s):
    for char in s_sub:
        if char not in {'A', 'T', 'G', 'C'}:
            return False
    return True

S = input()
length = len(S)
ans = 0
for i in range(length):
    for j in range(i + 1, length + 1):
        s_sub = S[i:j]
        if is_acgt(s_sub):
            ans = max(ans, len(s_sub))

print(ans)
