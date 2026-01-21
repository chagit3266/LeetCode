int singleNonDuplicate(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    int mid =0;
    while (left < right) {
        
        mid = left + (right - left) / 2;
        
        if (mid % 2 == 1)
            mid--;
        
        if(nums[mid] == nums[mid+1]){
            left = mid+2;
        }else{
            right = mid;
        }
    }
    return nums[left];
}