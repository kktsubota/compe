N = int(input())
As, Bs = list(), list()
for i in range(N):
    A, B = map(int, input().split())
    As.append(A)
    Bs.append(B)

Bs_with_index = sorted([(Bs[i], i) for i in range(len(Bs))])
indices = list(map(lambda b: b[1], Bs_with_index))

time = 0
for index in indices:
    time += As[index]
    if time > Bs[index]:
        print('No')
        break

else:
    print('Yes')