from typing import List


class Solution:
    def videoStitching(self, clips: List[List[int]], T: int) -> int:
        time = 0
        count = 0
        while True:
            max_t = -1
            for start, end in clips:
                if 0 <= start <= time:
                    max_t = max(max_t, end)

            count += 1
            if max_t >= T:
                break

            # cannot update
            if max_t == time:
                return -1

            time = max_t

        return count