class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int f=0;f<n-2;f++){
            int l=f+1, r = n-1;
            if(f>0 && nums[f]==nums[f-1]) continue;
            while(l<r){
                int sum = nums[f] + nums[l] + nums[r];
                if(sum==0){
                    ans.push_back({nums[f], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]) l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }
                else if(sum<0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};