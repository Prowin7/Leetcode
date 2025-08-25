class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[hi]){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }
        if(nums[lo]<nums[hi]) return nums[lo];
        else return nums[hi];
    }
};