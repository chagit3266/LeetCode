class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        nums.sort()
        closest = nums[0] + nums[1] + nums[2]

        for i in range(len(nums)-2):
            left, right = i + 1, len(nums) - 1
           
            while left < right:
                curr = nums[i] + nums[left] + nums[right]

                if abs(curr - target) < abs(closest - target):
                    closest = curr

                if curr < target:
                    left += 1
                elif curr > target:
                    right -= 1 
                else:
                    return curr
            
        return closest


        