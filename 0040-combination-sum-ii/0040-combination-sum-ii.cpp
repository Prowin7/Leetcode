class Solution {
public:
    void func(int i, int target, vector<int>& nums, vector<int>& vec, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(vec);
            return;
        }
        if (i >= nums.size() || target < 0) return;

        // ✅ Pick current element
        vec.push_back(nums[i]);
        func(i + 1, target - nums[i], nums, vec, ans);
        vec.pop_back();

        // \U0001f6ab Skip all duplicates of current element
        int next = i + 1;
        while (next < nums.size() && nums[next] == nums[i]) next++;

        // ❌ Not pick current element or any of its duplicates
        func(next, target, nums, vec, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> vec;
        func(0, target, candidates, vec, ans);
        return ans;
    }
};
