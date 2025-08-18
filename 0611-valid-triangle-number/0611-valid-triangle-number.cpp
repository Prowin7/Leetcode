class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
       
        int cnt=0;
        for(int i=2;i<n;i++){
            int left=0,right=i-1;
            while(left<right){
                if(nums[left]+nums[right]>nums[i]){
                    cnt+=(right-left);
                    right--;
                }
                else {
                    left++;
                }

            }
        }
        return cnt;
    }
};