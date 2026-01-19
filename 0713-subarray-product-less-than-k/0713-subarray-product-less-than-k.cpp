class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left=0;
        int right = 0;
        int prod = 1;
        int cnt=0;
        if(k<=1) return 0;
        while(right<n){
            prod*=nums[right];
           
            while(prod>=k){
                prod/=nums[left];
               
                left++;
            }    
           cnt+=(right-left+1);
           right++;
        }
        return cnt;
    }
};