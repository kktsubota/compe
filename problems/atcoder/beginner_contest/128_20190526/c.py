import itertools


def is_bright(switch, status, p):
    count = 0
    for s in switch:
        if status[s - 1]:
            count += 1
            
    return count % 2 == p


n, m = map(int, input().split())
switches = list()
for i in range(m):
    tmp = input().split()
    switches.append(list(map(int, tmp[1:])))

ps = list(map(int, input().split()))

count = 0
for status in itertools.product(*[[True, False]] * n):
    for switch, p in zip(switches, ps):
        if not is_bright(switch, status, p):
            break
    
    else:
        count += 1

print(count)