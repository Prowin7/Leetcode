class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=0;
        int hi=nums.size()-1;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if (mid % 2 == 1) mid--;
            if(nums[mid]==nums[mid+1]){
               lo=mid+2;
            }
            else{
                hi=mid;
            }
        }
        if (lo == hi) return nums[lo];
        return nums[hi];
    }
};