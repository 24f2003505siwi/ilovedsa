class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        numsset = set(nums)
        longest = 0
        for n in numsset:
            if n-1 not in numsset:
                length = 1
                while n+length in numsset:
                    length += 1
                longest = max(length, longest)
        return longest