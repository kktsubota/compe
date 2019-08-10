from typing import List

class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        sum_value = sum(A)
        if sum_value % 3 != 0:
            return False
        
        value = sum_value // 3
        
        cumsums = [0, 0, 0]
        j = 0
        for i in range(len(A)):
            cumsums[j] += A[i]
            if cumsums[j] == value:
                j += 1
                
            if j == 3:
                break

        if j != 3 or sum(A[i+1:]) != 0:
            return False
        else:
            return True

# a = [0,2,1,-6,6,7,9,-1,2,0,1]
# a = [0,2,1,-6,6,-7,9,1,2,0,1]
a = [3,3,6,5,-2,2,5,1,-9,4]
print(Solution().canThreePartsEqualSum(a))