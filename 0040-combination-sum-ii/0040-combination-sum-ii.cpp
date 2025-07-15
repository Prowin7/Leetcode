class Solution {
public:
    void func(int start, int target, vector<int>& nums, vector<int>& vec, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(vec);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue; // skip duplicates
            if (nums[i] > target) break;

            vec.push_back(nums[i]);
            func(i + 1, target - nums[i], nums, vec, ans);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> vec;
        func(0, target, candidates, vec, ans);
        return ans;
    }
};
