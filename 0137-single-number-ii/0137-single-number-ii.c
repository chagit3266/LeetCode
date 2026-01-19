int singleNumber(int* nums, int numsSize) {
   int one = 0,two = 0;
   for(int i= 0; i< numsSize; i++){
      one = (one ^ nums[i]) & ~two;
      two = (two ^ nums[i]) & ~one;
   }
   return one;
}