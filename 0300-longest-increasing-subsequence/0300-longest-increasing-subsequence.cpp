class Solution {
    int binary(int target, vector<int>&ans){
        int l = 0;
        int r = ans.size();
        while(l<=r){
            int mid = l+(r-l)/2;
            if(target==ans[mid]){
                return mid;
            }
            else if(target>ans[mid]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        
        int ind = 0;
        for(int i=0;i<n;i++){
            if(!ans.empty() && nums[i]>ans.back()){
                ans.push_back(nums[i]);

            }
            else {
                ind = binary(nums[i],ans);
                ans[ind] = nums[i];
            }
        }
        return ans.size();
    }
};