from collections import defaultdict


class Solution:
    def baseNeg2(self, N: int) -> str:
        # 2
        binary = '{:b}'.format(N)
        binary = list(map(int, binary))
        # -2
        # print(binary)
        binary_ans = defaultdict(int)
        for i in range(1, len(binary)+1):
            if i % 2 == 0 and binary[-i] == 1:
                binary_ans[i - 1] = 1
                binary_ans[i - 1 + 1] = 1
            else:
                binary_ans[i - 1] += binary[-i]
        # print(binary_ans)
        for key in range(100):
            if binary_ans[key] in {0, 1}:
                continue

            else:
                neg_carry = min(binary_ans[key] // 2, binary_ans[key + 1])
                binary_ans[key + 1] -= neg_carry
                binary_ans[key] -= neg_carry * 2
                    
                carry = binary_ans[key] // 2
                binary_ans[key] = binary_ans[key] % 2
                binary_ans[key + 1] += carry
                binary_ans[key + 2] += carry

        ans = ''
        keys = sorted(list(binary_ans.keys()))
        keys.reverse()
        for key in keys:
            ans += str(binary_ans[key])

        for i in range(len(ans)):
            if ans[i] != '0':
                break
        return ans[i:]


print(Solution().baseNeg2(14))