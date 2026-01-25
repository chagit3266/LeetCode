public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        int zero = 0;
        int mul = 1;
        int [] res = new int[nums.Length];
        for(int i = 0; i< nums.Length; i++){
            if(nums[i] == 0){
                zero ++;
                if(zero > 1)
                  return res;
            }else{
                mul *= nums[i];
            }
        }
        for(int i = 0; i< nums.Length; i++){
            if(zero == 0){
               res[i] = mul/ nums[i];
            }
            else if(nums[i] == 0){
                res[i] = mul;
            }else {
                 res[i] = 0;
            }
        }
        return res;
    }
}