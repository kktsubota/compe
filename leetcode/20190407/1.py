class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        indices_head, indices_tail = list(), list()
        offset = 0
        while True:
            # S[idx_h:idx_t]
            idx_h, idx_t = self.findPair(S[offset:])
            indices_head.append(offset + idx_h)
            indices_tail.append(offset + idx_t)
            offset = idx_t + offset
            if offset == len(S):
                break
        
        ans = ''
        for idx_h, idx_t in zip(indices_head, indices_tail):
            # to remove ( and )
            ans += S[idx_h + 1: idx_t - 1]
        return ans


    def findPair(self, S: str) -> tuple:
        num = 0
        for i in range(len(S)):

            if S[i] == '(':
                num += 1
                if num == 1:
                    head_idx = i

            elif S[i] == ')':
                num -= 1
                if num == 0:
                    return (head_idx, i + 1)

        raise RuntimeError


# s = '(()())(())'
# s = '(()())(())(()(()))'
# s = '()()'
# print(Solution().removeOuterParentheses(s))

