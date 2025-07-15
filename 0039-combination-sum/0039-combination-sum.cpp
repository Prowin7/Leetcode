class Solution {
public:
void func(int start,int sum,int target,vector<int>& nums,vector<int>& vec,vector<vector<int>>& ans){
    if(sum==target) {
        ans.push_back(vec);
        return;
    }
    if(sum>target || start>=nums.size()) return;
    vec.push_back(nums[start]);
    func(start,sum+nums[start],target,nums,vec,ans);
    vec.pop_back();
    func(start+1,sum,target,nums,vec,ans);




}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
        vector<vector<int>> ans;
        vector<int> vec;
        func(0,0,target,candidates,vec,ans);
        return ans;
    }
};