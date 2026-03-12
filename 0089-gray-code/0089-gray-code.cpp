class Solution {
public:
    int nextGrayCode(int n) {
        return n ^ (n >> 1);
    }
    vector<int> grayCode(int n) {
        // vector<int> nums;
        // int total = 1 << n;
        // for(int i = 0; i < total; i++){
        //     nums.push_back(nextGrayCode(i));
        // }
        // return nums;

        vector<int> nums;
        if(n < 1)
           return nums;

        nums.push_back(0);

        for(int i = 0; i < n; i++){
            for(int j = nums.size()-1; j >= 0 ; j--){
                nums.push_back(nums[j] | (1 << i));
            }
        }
        return nums;
    }
};