/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
  
    int i = digitsSize - 1;
    while(i >= 0){
       if(digits[i] < 9){
          digits[i]++;
           *returnSize = digitsSize;
          return digits;
       }
       else{
          digits[i] = 0;
       }
       i--;
    }
    int* res = malloc(sizeof(int) * (digitsSize + 1));
    res[0] = 1;
    for (int j = 1; j <= digitsSize; j++) {
        res[j] = 0;
    }

    *returnSize = digitsSize + 1;
    return res;
}