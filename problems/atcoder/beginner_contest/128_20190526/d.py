import heapq
import copy

N, K = map(int, input().split())
Vs = list(map(int, input().split()))

ans = 0
for kr in range(min(N, K) + 1):
    for kl in range(min(N - kr, K - kr) + 1):
        kp = min(K - kr - kl, kr + kl)
        # print(kr, kl, kp)
        if kr != 0:
            vs = Vs[-kr:] + Vs[:kl]
        else:
            vs = Vs[:kl]
        
        length = len(vs)
        if length == 0:
            continue
        vs = copy.deepcopy(vs)
        heapq.heapify(vs)
        # less than the number of outputs
        for i in range(min(kp, length)):
            if vs[0] < 0:
                heapq.heappop(vs)
            else:
                break
        value = sum(vs)
        ans = max(value, ans)

print(ans)

