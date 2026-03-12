class Solution {
public:
    int nextGrayCode(int n) {
        return n ^ (n >> 1);
    }
    vector<int> grayCode(int n) {
        vector<int> nums;
        int total = 1 << n;
        for(int i = 0; i < total; i++){
            nums.push_back(nextGrayCode(i));
        }
        return nums;
    }
};