#include <vector>
class Solution {
public:
    bool canJump(vector<int>& nums) {

       int n=nums.size();
       int i=n-2;
       std::vector<bool> dp(n,0);
       dp[n-1]=true;
       while(i>=0){
          for(int j=i+1; j<=nums[i]+i&& j<n;++j){
            if(dp[j]){
                dp[i]=true;
                break;
            }
          }
          i--;
       }
       return dp[0]; 
    }
};