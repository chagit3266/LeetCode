char findTheDifference(char* s, char* t) {
    int res = 0;
    while (*s) {
        res ^= *s;
        s++;
    }

    while (*t) {
        res ^= *t;
        t++;
    }
    return (char)res;
}