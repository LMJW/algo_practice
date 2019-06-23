from typing import List

class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        ans = 0
        d = {0:-1}
        l = 0
        total = 0
        for r,v in enumerate(nums):
            total += v
            t = total-k
            if t == 0:
                ans = max(ans, r+1)
            elif t in d:
                ans = max(ans, r-d[t])
            else:
                pass

            if total not in d:
                d[total] = r

        return ans