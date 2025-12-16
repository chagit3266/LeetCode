class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
            auto it = find(nums.begin() + i +1, nums.end(), num);
            if (it != nums.end()) {
                int idx = it - nums.begin();
                 return vector<int>{i, idx};
            }
        }
        return vector<int>{};
    }
};