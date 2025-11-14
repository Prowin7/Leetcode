class Solution {
    vector<vector<int>> ans;
    
    void backtrack(vector<int>& used, vector<int>& cur, vector<int>&nums ){
        if(cur.size()==nums.size()){
            ans.push_back(cur);
            return ;
        }
        for(int i =0;i<nums.size();i++){
            if(used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;

            used[i] = true;
            cur.push_back(nums[i]);

            backtrack(used, cur, nums);

            cur.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> cur;
        sort(nums.begin(),nums.end());
        vector<int> used(nums.size()+1,false);
        backtrack(used, cur, nums);
        
        return ans;
    }
};