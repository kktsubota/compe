n, x, m = map(int, input().split())
ans = 0
prev_set = set()
prev_list = list()
ans_hist = list()
r = x

for i in range(n):
    if i == 0:
        pass
    else:
        r = (r * r) % m
    
    if r == 0:
        break
    
    if r in prev_set:
        index = prev_list.index(r)
        period = i - index
        count = (n - index) // period
        rest = (n - index) % period

        # ans = sum(prev_list[:index])
        # ans += sum(prev_list[index:i]) * count
        if index == 0:
            ans += ans * (count - 1)
        else:
            ans += (ans - ans_hist[index - 1]) * (count - 1)

        ans += sum(prev_list[index:index+rest])
        # ans += (ans_hist[index + rest - 1] - ans_hist[index - 1])
        break
    else:
        ans += r
        prev_set.add(r)
        prev_list.append(r)
        ans_hist.append(ans)
print(ans)
