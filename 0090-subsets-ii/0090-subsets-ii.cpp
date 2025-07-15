    class Solution {
    public:
    void func(int i,vector<int> &vec,vector<int> &nums,vector<vector<int>> &ans){
        
           if(i==nums.size()){
            ans.push_back(vec);
            return ;
           }
           vec.push_back(nums[i]);
           func(i+1,vec,nums,ans);
           vec.pop_back();
           while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
           func(i+1,vec,nums,ans);
        }

    
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            vector<int> vec;
            func(0,vec,nums,ans);
            
            
            return ans;
        }
    };