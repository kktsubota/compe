import itertools


n, m, x = map(int, input().split())
book_costs = list()
book_skills = list()
for i in range(n):
    line = list(map(int, input().split()))
    book_cost = line[0]
    book_skill = line[1:]
    book_costs.append(book_cost)
    book_skills.append(book_skill)
    

ans = 12 * 101001
for flags in itertools.product(*[[True, False]] * n):
    cost = 0
    skill = [0 for i in range(m)]
    for i, flag in enumerate(flags):
        if flag:
            cost += book_costs[i]
            for j, skl in enumerate(book_skills[i]):
                skill[j] += skl
    
    if min(skill) >= x:
        ans = min(ans, cost)

if ans == 12 * 101001:
    print(-1)
else:
    print(ans)
    
