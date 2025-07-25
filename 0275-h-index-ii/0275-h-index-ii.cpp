class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n;
        
        while(left<right){
           int mid=left+(right-left)/2;
           if(nums[mid]==n-mid) return n-mid;
            if(nums[mid]>=n-mid){
                right=mid;
            }
            else{
                left=mid+1;
            }

        }
        return n-left;
    }
};