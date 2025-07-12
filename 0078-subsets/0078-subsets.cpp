class Solution {
public:

void pick(int i,int n,vector<int>& nums,vector<vector<int>> &ans,vector<int> &a){
    if(i==n){
        ans.push_back(a);
        return;
    }
    a.push_back(nums[i]);
    pick(i+1,n,nums,ans,a);
    a.pop_back();
    pick(i+1,n,nums,ans,a);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> a;
        pick(0,n,nums,ans,a);
           
        
        return ans;
    }
};