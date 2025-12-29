class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        len_max = 0
        start_temp = 0
        dp = {}

        for i in range(len(s)):
            idx = s[i]
            if idx in dp and dp[idx] >= start_temp:
                start_temp = dp[idx] + 1
            
            dp[idx] = i
            len_max = max((i - start_temp + 1),len_max)

        return len_max
        