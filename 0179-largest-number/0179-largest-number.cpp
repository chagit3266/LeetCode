#include <algorithm>

class Solution {
public:
    static bool compare(string &a,string &b){
       return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int num:nums){
            arr.push_back(to_string(num));
        }
        std::sort(arr.begin(),arr.end(),compare);

        string res;
        for(string num:arr){
            res+=num;
        }
        if(res[0]=='0')res="0";
        return res;
    }
};