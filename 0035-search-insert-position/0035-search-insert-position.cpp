class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<target){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        if(nums[lo]>=target) return lo;
        if(nums[hi]>=target) return hi;
        return n;
    }
    
};