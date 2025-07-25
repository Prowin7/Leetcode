class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        // for(int i=1;i<n;i++){
        //     if(nums[i]<nums[i-1]){
        //         return nums[i];
        //     }
        // }
        // return nums[0];

        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;

            if(mid>0&&nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            if(mid<n-1&&nums[mid]>nums[mid+1]) return nums[mid+1];
            if(nums[mid]>nums[left]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
            
        }
        return nums[0];
    }

};