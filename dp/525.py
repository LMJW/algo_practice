from typing import List

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        z = 0
        d = {}
        ans = 0
        for i,v in enumerate(nums):
            if v == 0:
                z += 1
            # number of 1's substract number of 0's
            dif = i+1-z-z
            if dif == 0:
                ans = i+1
            elif dif in d:
                ans = max(ans, i-d[dif])

            if dif not in d:
                d[dif] = i
        return ans
