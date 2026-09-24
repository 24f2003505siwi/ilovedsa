class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        max1s = 0
        cur = 0
        for num in nums:
            if num == 1:
                cur += 1
                max1s = max(max1s, cur)
            else:
                cur = 0
        return max1s