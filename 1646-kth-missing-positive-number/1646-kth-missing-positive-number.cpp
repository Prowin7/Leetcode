class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if((nums[mid]-(mid+1))<k){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        if(nums[lo]-(lo+1)>=k) return k+lo;
        if(nums[hi]-(hi+1)>=k) return k+hi;
        return  n+k;
    }
};