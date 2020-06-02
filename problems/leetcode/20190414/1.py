class Solution:
    def divisorGame(self, N: int) -> bool:
        self.pre_calc(N)
        return self.cache[N]
    
    def pre_calc(self, N: int):
        self.cache = dict()
        for n in range(1, N + 1):
            candidates = [x for x in range(1, n) if n % x == 0]
            if len(candidates) == 0:
                self.cache[n] = False
            
            for cand in candidates:
                # find best move
                if not self.cache[n - cand]:
                    self.cache[n] = True
                    break
            else:
                self.cache[n] = False


sol = Solution()
sol.pre_calc(10)
print(sol.cache)