class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;

            if(nums[mid]> nums[right]){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        int ind=left;
        if(nums[left]==target) return left;
        int s1=0;
        int s2=left;
        int e1=left-1;
        int e2=n-1;
        while(s1<=e1){
            int mid=s1+(e1-s1)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                    e1=mid-1;
            }
            else{
                s1=mid+1;
            }
        }
        while(s2<=e2){
            int mid=s2+(e2-s2)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e2=mid-1;

            }
            else{
                s2=mid+1;
            }
        }
        return -1;
    }
};