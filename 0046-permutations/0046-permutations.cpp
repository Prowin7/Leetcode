class Solution {
    vector<vector<int>> ans;
    void backtrack(vector<int>&used ,vector<int>& cur, vector<int>& nums){
        if(cur.size()==nums.size()){
            ans.push_back(cur);
            return ;
        }
        for(int i =0;i<nums.size();i++){
            if(!used[i]){
                used[i] = true;
                cur.push_back(nums[i]);
                backtrack(used, cur, nums);
                used[i] = false;
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<int> used(nums.size()+1,false);
        backtrack(used, cur, nums);
        return ans;
    }
};