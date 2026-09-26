class Solution:
    def maxScore(self, cardPoints: list[int], k: int) -> int:
        cursum = sum(cardPoints[:k])    #sum of first k elements
        maxsum = cursum
        for i in range(k):
            cursum -= cardPoints[k - i - 1]
            cursum += cardPoints[-i - 1]
            maxsum = max(maxsum, cursum)
        return maxsum