n = int(input())
s = list(input())
q = int(input())

flip_flag = False
A = [i for i in range(q)]
B = [i for i in range(q)]
T = [i for i in range(q)]
for i in range(q):
    t, a, b = map(int, input().split())
    A[i] = a - 1
    B[i] = b - 1
    T[i] = t

for a, b, t in zip(A, B, T):
    if t == 2:
        flip_flag = not flip_flag
    else:
        if flip_flag:
            if a < n:
                a += n
            else:
                a -= n

            if b < n:
                b += n
            else:
                b -= n
        s[a], s[b] = s[b], s[a] 
           
if flip_flag:
    s = s[n:] + s[:n]

print("".join(s))
