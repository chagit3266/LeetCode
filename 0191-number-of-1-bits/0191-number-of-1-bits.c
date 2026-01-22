int hammingWeight(int n) {
    int counter = 0;
    while(n != 0){
       counter++;
       n &= n-1;
    }
    return counter;
}