class Solution {
public:
    void Backtracking(vector<int> &candidates, int i, int target,vector<int> &tmp,       vector<vector<int>> &res){
        
        if(target == 0){
            res.push_back(tmp);
            return;
        }
        if (i >= candidates.size() || target < 0)
            return;
        
        tmp.push_back(candidates[i]);
        Backtracking(candidates, i, target - candidates[i], tmp, res); // ← שים לב: i, לא i+1
        tmp.pop_back();

        Backtracking(candidates, i+1, target, tmp, res);
        
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        Backtracking(candidates, 0, target, tmp, res);
         vector<vector<int>> res2;
        for (auto &vec : res) {
            vector<int> inner;
            inner = vec;
            res2.push_back(inner);
        }
        return res2;
    }
};