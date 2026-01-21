/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int a_xor_b=0;
    for(int i=0; i<numsSize; i++){
        a_xor_b ^= nums[i];
    }
    unsigned int mask = (unsigned int)a_xor_b & (-(unsigned int)a_xor_b);
   
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = 0;
    res[1] = 0;
    
    for(int i=0; i<numsSize; i++){
        if(nums[i] & mask)
            res[0] ^= nums[i];
        else
            res[1] ^= nums[i];
    }
    *returnSize = 2;
    return res;
}