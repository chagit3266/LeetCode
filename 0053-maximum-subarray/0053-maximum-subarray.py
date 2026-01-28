class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prev_sum = nums[0]
        max_sum = nums[0]

        for n in nums[1:]:
            prev_sum = max(n,prev_sum+n)
            max_sum = max(prev_sum, max_sum)

        return max_sum
        