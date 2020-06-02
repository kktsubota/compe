n = int(input())
a = list(map(int, input().split()))


del_flag = [0 for i in range(n)]
value = 1
for i in range(n):
    if a[i] == value:
        value += 1
        continue
    del_flag[i] = 1

ans = sum(del_flag)
if ans == n:
    print(-1)
else:
    print(ans)
