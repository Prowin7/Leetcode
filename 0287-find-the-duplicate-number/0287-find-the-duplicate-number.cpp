class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //binary search
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<right){
            int mid=(right-left)/2+left;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid){
                    cnt++;
                }
            }
            if(cnt>mid){
                right=mid;
            }
            else {
                left=mid+1;
            }
        }
        return left;
    }
};