long long maximumScore(int* nums, int numsSize) {
    long long* prefixSum = malloc(sizeof(long long) * numsSize);
    int* suffixMin = malloc(sizeof(int) * numsSize);
    
    prefixSum[0] = nums[0];
    for(int i = 1; i< numsSize; i++){
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    
    suffixMin[numsSize - 2] = nums[numsSize - 1];
    for(int i = numsSize - 3; i >= 0; i--){
        suffixMin[i] = (nums[i+1] < suffixMin[i+1])?nums[i+1] :  suffixMin[i+1];
    }
    
    long long maxScore = prefixSum[0] - suffixMin[0];
    for(int i = 0; i< numsSize-1; i++){
        long long score = prefixSum[i] - suffixMin[i];
        if(score > maxScore){
            maxScore = score;
        }
    }
    free(prefixSum);
    free(suffixMin);
    return maxScore;
}