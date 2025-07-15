class Solution {
public:
vector<vector<int>> ans;
void func(vector<int> &vec,vector<bool> &used,vector<int> &nums){
    if(vec.size()==nums.size()){
        ans.push_back(vec);
        return ;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i]) continue;
        if(i>0&&nums[i]==nums[i-1]&&!used[i-1]) continue;
        
 
        vec.push_back(nums[i]);
        used[i]=true;
        func(vec,used,nums);
        used[i]=false;
        vec.pop_back();
        
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> vec;
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size()+1,false);
        func(vec,used,nums);
        return ans;
    }
};