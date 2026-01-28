class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prev1 = 0
        prev2 = 0

        for n in nums:
            curr = max(prev1, prev2 + n)
            prev2 = prev1
            prev1 = curr

        return prev1