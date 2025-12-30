long long maximumScore(int* nums, int numsSize) {
    int* suffixMin = malloc(sizeof(int) * numsSize);
    
    suffixMin[numsSize - 2] = nums[numsSize - 1];
    for(int i = numsSize - 3; i >= 0; i--){
        suffixMin[i] = (nums[i+1] < suffixMin[i+1])?nums[i+1] :  suffixMin[i+1];
    }
    
    long long prefixSum = nums[0];
    long long maxScore = prefixSum - suffixMin[0];

    for(int i = 0; i< numsSize-1; i++){
        long long score = prefixSum - suffixMin[i];
        prefixSum += nums[i+1];
        if(score > maxScore){
            maxScore = score;
        }
    }
    free(suffixMin);
    return maxScore;
}