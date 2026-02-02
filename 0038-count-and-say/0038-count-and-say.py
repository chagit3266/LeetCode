class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = "1"
        for _ in range(n-1):
            temp = s
            s = ""
            
            count = 1
            for i in range(1, len(temp)):
                if temp[i] == temp[i - 1]:
                    count += 1
                else:
                    s += str(count) + temp[i - 1]
                    count = 1
            s += str(count) + temp[-1]

        return s

        