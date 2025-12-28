class Solution {
public:
    int reverse(int x) {

        long long new_num = 0;

        while(x != 0){
            int digit = x % 10;
            new_num *= 10;
            new_num += digit;
            x /= 10;
        }
         if(new_num > INT_MAX || new_num < INT_MIN ){
                return 0;
            }
        return (int)new_num;
    }
};