long long maximumScore(int* nums, int numsSize) {
    
    long long prefixSum = 0;
    for(int i = 0; i < numsSize-1; i++){
        prefixSum += nums[i];
    }

    int suffixMin = nums[numsSize -1];
    
    long long maxScore = prefixSum - suffixMin;

    for(int i = numsSize-2; i >= 0; i--){
        
        long long score = prefixSum - suffixMin;
        
        prefixSum -= nums[i];
        suffixMin = (suffixMin < nums[i])? suffixMin: nums[i];
        
        if(score > maxScore){
            maxScore = score;
        }
    }

    return maxScore;
}