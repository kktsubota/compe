class Solution:
    def clumsy(self, N: int) -> int:
        nums = list(range(1, N+1))
        nums.reverse()
        eq = ''
        for i in range(len(nums)):
            eq += 'nums[{}]'.format(i)
            
            # remove last calc
            if i == (len(nums) - 1):
                break

            if i % 4 == 0:
                eq += '*'
            elif i % 4 == 1:
                eq += '//'
            elif i % 4 == 2:
                eq += '+'
            elif i % 4 == 3:
                eq += '-'

        return eval(eq)


print(Solution().clumsy(10))