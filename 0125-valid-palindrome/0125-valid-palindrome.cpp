class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int la = s.size()-1;

        while(st <= la){

            while (st < la && !isalnum(s[st])) st++;
            while (st < la && !isalnum(s[la])) la--;
            
            if (tolower(s[st]) != tolower(s[la]))
                return false;
                
            st++;
            la--;

        }

        return true;
    }
};