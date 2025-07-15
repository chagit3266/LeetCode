class Solution {
public:
    void swap(int i,int j,vector<int>&nums){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }

    void sortColors(vector<int>& nums) {
       int left=0;
       int right=nums.size()-1;
       int mid=0;

       while(mid<=right){
        if(nums[mid]==0){
          swap(mid,left,nums);
          left++;
          mid++;
        }else if(nums[mid]==2){
          swap(mid,right,nums);
          right--;
        }else{
            mid++;
        }
       }    
    }
};