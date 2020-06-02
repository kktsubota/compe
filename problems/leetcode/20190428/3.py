# copy from
# https://leetcode.com/problems/uncrossed-lines/discuss/282952/O(n2-lg-n)-Python-DP-solution
import bisect
import collections
from functools import lru_cache

A = list(map(int, input().split()))
B = list(map(int, input().split()))

# h[value] = [idx_0, idx_1, ...] of B
h = collections.defaultdict(list)
for i, v in enumerate(B):
    h[v].append(i)

# None denotes unlimited maxsize
@lru_cache(None)
def dp(i: int, j: int) -> int:
    """
    Args:
        i (int): index for A
        j (int): index for B (that matches with A[i])
    """
    if i >= len(A):
        return 0
    # index i is not matched
    best = dp(i+1, j)
    
    # match index i with first elem in B at index j or higher
    s = bisect.bisect_left(h[A[i]], j)
    
    # couldn't match (j is higher than any element of h[A[i]])
    if s >= len(h[A[i]]):
        return best
    best = max(best, 1 + dp(i+1, h[A[i]][s]+1))
    return best

print(dp(0, 0))