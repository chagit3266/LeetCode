int xorTo(int n) {
    switch(n%4){
        case 0:
            return n;
            break;
        case 1:
            return 1;
            break;
        case 2:
            return n+1;
            break;
        default: // case 3 and other
            return 0;
            break; 
    }
}

int xorOperation(int n, int start) {
    // nums[i] = start + i*2
    // start = 2*s + b ( s = start/2 , b = start%2)
    // nums[i] = 2(s + i) +b
    // XOR(nums) = (XOR(s , s+1,..., s+n-1)<<1) | (b & (n%2))
    

    int num = 0; 
    int s = start >> 1;          // start / 2
    int b = start & 1;           // start % 2

    //XOR(a..b) = xorTo(b) ^ xorTo(a-1)
    int mid = xorTo(s + n - 1) ^ xorTo(s - 1);

    return (mid << 1) | (b & (n & 1)); 
}