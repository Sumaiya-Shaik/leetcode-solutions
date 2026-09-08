class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates, target, 0, combination, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int remaining, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(combination);
            return;
        }
        
        if (remaining < 0) return;
        
        for (int i = start; i < candidates.size(); i++) {
            combination.push_back(candidates[i]);
            backtrack(candidates, remaining - candidates[i], i, combination, result);
            combination.pop_back();
        }
    }
};