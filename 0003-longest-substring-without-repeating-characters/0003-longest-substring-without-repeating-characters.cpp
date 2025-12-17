class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        if (n <= 1)
            return n;
        int max = 0;
        int left = 0;
        vector<int> last(128, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i];
            if (last[c] >= left) {
                left = last[c] + 1;
            }
            last[c] = i;
            if ((i - left + 1) > max) {
                max = i - left + 1;
            }
        }
        return max;
    }
};