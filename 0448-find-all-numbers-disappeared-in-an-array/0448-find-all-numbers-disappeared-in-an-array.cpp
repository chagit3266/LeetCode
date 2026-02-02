class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {

            while (nums[i] != i + 1 && nums[i] != 0) {
                int temp = nums[nums[i] - 1];
                if (temp == nums[i])
                    nums[i] = 0;
                else {
                    nums[nums[i] - 1] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        vector<int> res;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] == 0){
               res.push_back(i + 1);
            }
        }
        return res;
    }
};