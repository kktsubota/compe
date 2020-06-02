from typing import List


class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        count_a = self.count(A)
        count_b = self.count(B)
        
        for i in range(1, 7):
            if count_a[i] + count_b[i] >= len(A):
                target = i
                break
        
        else:
            return -1

        for a, b in zip(A, B):
            if a != target and b != target:
                return -1

        # possible
        return len(A) - max(count_a[target], count_b[target])
    
    def count(self, l: List[int]) -> dict:
        # default dict
        counter = {i: 0 for i in range(1, 7)}
        for elem in l:
            counter[elem] += 1
        return counter
