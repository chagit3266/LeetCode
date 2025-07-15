class Solution {
public:
    void backtrack(std::string digits, int index, const char**arr, std::string &path, vector<std::string> &res){
         if(index==digits.size()){
            res.push_back(path);
            return;
         }
         const char* letters=arr[digits[index]-'0'];
         if(!letters)return;
         for(int i=0;letters[i];++i){
             path.push_back(letters[i]);
             backtrack(digits,index+1,arr,path,res);
             path.pop_back();
         }
    }
    vector<string> letterCombinations(string digits) {
        
        const char* arr[10]={
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        int n=digits.size();
        vector<std::string> res;

        if(digits.empty())return res;

        std::string path;

        backtrack(digits,0,arr,path,res);

        return res;
    }

};