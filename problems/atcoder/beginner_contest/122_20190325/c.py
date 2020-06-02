N, Q = map(int, input().split())
S = input()

indices = list()
for i in range(Q):
    l, r = map(int, input().split())
    indices.append((l - 1, r - 1))

# count[i]: count of "AC" from index 0 to index i
count = [0 for i in range(N)]
# index of C
for i in range(N - 1):
    if S[i:i+2] == 'AC':
        count[i+1] = count[i] + 1
    
    else:
        count[i+1] = count[i]

for beg, end in indices:
    if beg == 0:
        print(count[end])
    
    else:
        is_boundary = S[beg-1:beg+1] == 'AC'
        print(count[end] - count[beg - 1] - int(is_boundary))
    