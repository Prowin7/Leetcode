class Solution {
public:
 vector<vector<int>> ans;
 void func(vector<int> &vec,vector<int> &nums,vector<bool> &used){
        if(vec.size()==nums.size()){
            ans.push_back(vec);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                vec.push_back(nums[i]);
                used[i]=true;
                func(vec,nums,used);
                vec.pop_back();
                used[i]=false;
            }
        }
 }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec;
        vector<bool> used(n+1,false);
        func(vec,nums,used);
        return ans;
    }
};