/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
    *returnSize = encodedSize +1;
    int * res = malloc(sizeof(int) * (*returnSize));
    res[0] = first;
    for(int i=1; i<= encodedSize; i++){
        res[i] = res[i-1] ^ encoded[i-1];
    }
    return res;
}