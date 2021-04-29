n, x = map(int, input().split())
A = list(map(int, input().split()))

indices = set()
for i, a in enumerate(A):
    if a == x:
        indices.add(i)

print_flag = True
for i, a in enumerate(A):
    if i not in indices:
        if print_flag:
            print(a, end="")
            print_flag = False
        else:
            print(" {}".format(a), end="")

print()
