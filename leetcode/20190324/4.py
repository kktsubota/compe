S = "0110"
N = 4

def func():
    length = len(S)
    values = set()
    # O(len(S)**2)
    for i in range(length):
        for j in range(i + 1, length + 1):
            subs = S[i:j]
            # print(subs)
            v = int(subs, 2)
            # v = eval("0b" + subs)
            values.add(v)

    # print(values)
    if N > len(values):
        return False
    # O(N)
    for k in range(1, N+1)[::-1]:
        if k not in values:
            return False

    return True
    # O(min(N, len(values))) ==  O(len(S)**2)
    # return not {i for i in range(1, N+1)} - values

print(func())