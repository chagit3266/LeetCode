class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int select1 = 0, select2 = 0, count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == select1){
                count1++;
            }else if(nums[i] == select2){
                count2++;
            }else if(count1 == 0){
                select1 = nums[i];
                count1 = 1;
            }else if(count2 == 0){
                select2 = nums[i];
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for (int num : nums) {
            if (num == select1) count1++;
            else if (num == select2) count2++;
        }
         
         vector<int> result;
        if (count1 > nums.size() / 3) result.push_back(select1);
        if (count2 > nums.size() / 3) result.push_back(select2);

        return result;
    }
};