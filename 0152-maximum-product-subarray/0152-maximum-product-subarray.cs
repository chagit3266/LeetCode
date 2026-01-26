public class Solution {
    public int MaxProduct(int[] nums) {
        int maxMul = nums[0];
        int maxCur = nums[0];
        int minCur = nums[0];
        
        for(int i = 1; i< nums.Length; i++){
            if(nums[i] < 0){
               int temp = maxCur;
               maxCur = minCur;
               minCur = temp;
            }
            maxCur = Math.Max(nums[i], maxCur * nums[i]);
            minCur = Math.Min(nums[i], minCur * nums[i]);

            maxMul = Math.Max(maxMul, maxCur);
        }
        return maxMul;
    }
}