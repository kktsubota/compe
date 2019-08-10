from typing import List
import string
import re


class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        ans = [self.match(query, pattern) for query in queries]
        return ans

    def match(self, query, pattern):
        indices = list()
        for i, p_c in enumerate(pattern):
            if p_c in string.ascii_uppercase:
                indices.append(i)
        indices.append(len(pattern))
        patterns = list()
        for idx_1, idx_2 in zip(indices[:-1], indices[1:]):
            patterns.append(pattern[idx_1:idx_2])
        template = '[a-z]*'
        for ps in patterns:
            for p in ps:
                template += p
                template += '[a-z]*'
        return bool(re.fullmatch(template, query))
        