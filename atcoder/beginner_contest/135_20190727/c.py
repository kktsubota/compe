n = int(input())
As = list(map(int, input().split()))
Bs = list(map(int, input().split()))

beats = list()
count = 0
for i in range(n):
    beat = min(Bs[i], As[i])
    count += beat
    Bs[i] -= beat
    As[i] -= beat

    beat = min(Bs[i], As[i + 1])
    count += beat
    Bs[i] -= beat
    As[i + 1] -= beat

    # print(As)
    # print(Bs)
    
print(count)
# print(beats)

# if As[n] > Bs[n - 1]:
#     beat = Bs[n - 1]
# else:
#     beat = As[n]
