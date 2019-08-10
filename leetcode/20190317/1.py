class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        ans = 0
        for i, j in itertools.combinations(range(len(time)), 2):
            if (time[i] + time[j]) % 60 == 0:
                ans += 1
        return ans

        ans = 0

        time = numpy.array(time)
        count = dict()
        for i in range(60):
            count[i] = (time % 60 == i).sum()
        
        ans = 0
        for i in range(1, 30):
            ans += count[i] * count[60 - i]
        
        if count[0] != 0:
            ans += count[0] * (count[0] - 1) // 2
        
        if count[30] != 0:
            ans += count[30] * (count[30] - 1) // 2
        return ans
        
            