class Solution:
    def smallestSubsequence(self, text: str) -> str:
        ans = ''
        cs = set(text)
        # print(cs)
        
        i = 1
        while len(text) != 0:
            # print(text, cs, i)
            # missing c
            if len(set(text[i:])) != len(cs):
                c_main = text[i-1]
                cs_rm = list()
                head = text[:i]
                while len(head) != 0:
                    # print('head', head, 'c_main', c_main)
                    c, j = min([(c, j) for j, c in enumerate(head)])
                    ans += c
                    cs.remove(c)
                    cs_rm.append(c)
                    head = head[j+1:].replace(c, '')
                    if c == c_main:
                        break

                # print('remove', cs_rm)
                tail = text[i:]
                for c in cs_rm:
                    tail = tail.replace(c, '')
                text = head + tail
                i = 1

            else:
                i += 1
        return ans

# s = 'accaccbbcc'
# s = 'bdfecedcbfcfeaaffdbaeeabadbbbddddcafdfeeeebfcdabcfaadecddccdefcabedbebbdcbdfefeffcbbeaefaeefeeceadea'
s = "edgebcbddfhafbcafbggbaadchcehhdaagfadedchbgbeadbde"
print(Solution().smallestSubsequence(s))
