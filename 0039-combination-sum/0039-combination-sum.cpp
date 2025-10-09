class Solution {
    vector<vector<int>> ans;
    void backtrack(int i, int target,vector<int>& candidates,vector<int>&comb){
        if(target==0){
            ans.push_back(comb);
            return ;
        }
        if(i==candidates.size()) return;
        if(target-candidates[i]>=0){
            comb.push_back(candidates[i]);
            backtrack(i,target-candidates[i],candidates,comb);
            comb.pop_back();
        }
        backtrack(i+1,target,candidates,comb);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n =candidates.size();
        vector<int> comb;
        backtrack(0,target,candidates,comb);
        return ans;
    }
};