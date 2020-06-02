MOD = 1000000007


n = int(input())
A = list(map(int, input().split()))


ans = 1
counter = [0, 0, 0]
for i in range(n):
    index = list()
    for j in range(len(counter)):
        if counter[j] == A[i]:
            index.append(j)

    ans *= len(index)
    ans = ans % MOD
    if len(index) == 0:
        break
    else:
        counter[index[0]] += 1

print(ans)
