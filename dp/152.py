from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = imax = imin = nums[0]
        for v in nums[1:]:
            if v < 0:
                imax, imin = imin, imax
            imax = max(v, imax * v)
            imin = min(v, imin * v)
            ans = max(ans, imax)
        return ans