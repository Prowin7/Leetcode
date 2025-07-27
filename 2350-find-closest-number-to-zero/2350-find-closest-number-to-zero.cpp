class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int close=INT_MAX;
        int n=nums.size();
        int ind;
        for(int i=0;i<n;i++){
            int dis=abs(nums[i]);
            close=min(close,dis);
        }

        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            if(close==abs(nums[i])){
                ans=max(ans,nums[i]);
            }
        }
    
        return ans;
        
    }
};