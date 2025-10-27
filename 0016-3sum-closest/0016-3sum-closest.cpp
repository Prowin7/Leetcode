class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int dis=INT_MAX;
        int ans;
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                int prev = abs(target-sum);
                if(prev<dis){
                    ans = sum;
                    dis=prev;
                }
                if(sum>target){
                    r--;
                }
                else if(sum<target){
                    l++;
                }
                else {
                    return sum;
                }
            }
        }
        return ans;
    }
};