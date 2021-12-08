n, x = map(int, input().split())
a_list = list(map(int, input().split()))
searched = [False for _ in range(len(a_list))]

while True:
    # cyclic
    if searched[x - 1]:
        break

    searched[x - 1] = True
    x = a_list[x - 1]

print(sum(searched))
