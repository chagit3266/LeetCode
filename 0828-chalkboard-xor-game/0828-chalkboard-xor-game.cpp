class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int num_xor=0;
        for(int num:nums){
            num_xor^=num;
        }
        if(num_xor==0)return true;

        if(nums.size()%2==0)return true;

        return false;
    }
};