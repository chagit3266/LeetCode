int getSum(int a, int b) {
    unsigned int carry;
    while (b != 0) {
        carry = (unsigned int)(a & b);
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}
